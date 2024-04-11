uses
  math;
const
  eps=1e-4;
var
  d1,d2,d3,r,s,x0,y0,d,dx,dy,a1,b1,c1,a2,b2,c2,x1,y1,x2,y2,x3,y3,ug1,ug2,ug3:double;
  i:longint;
  function ok(a,b:double):boolean;
    var
      x:double;
    begin
      x:=trunc((a+100*b+eps)/b);
      x:=x*b;
      ok:=abs(x-a-100*b)<eps;
    end;
begin
  read(x1,y1,x2,y2,x3,y3);
  a1:=x2-x1;
  b1:=y2-y1;
  c1:=-a1*(x1+x2)/2-b1*(y1+y2)/2;

  a2:=x3-x2;
  b2:=y3-y2;
  c2:=-a2*(x2+x3)/2-b2*(y2+y3)/2;

  d:=-a1*b2+b1*a2;
  dy:=a1*c2-c1*a2;
  dx:=c1*b2-b1*c2;
  x0:=dx/d;
  y0:=dy/d;
  x1:=x1-x0;y1:=y1-y0;
  x2:=x2-x0;y2:=y2-y0;
  x3:=x3-x0;y3:=y3-y0;
  r:=sqrt(x1*x1+y1*y1);
  d1:=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
  d2:=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
  d3:=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
{  ug1:=arccos((2*r*r-d1*d1)/(2*r*r));
  ug2:=arccos((2*r*r-d2*d2)/(2*r*r));
  ug3:=arccos((2*r*r-d3*d3)/(2*r*r));}
  ug1:=arctan2(x1,y1);
  ug2:=arctan2(x2,y2);
  ug3:=arctan2(x3,y3);
  for i:=3 to 100 do
    if (ok(ug1-ug2,2*pi/i))and(ok(ug2-ug3,2*pi/i))and(ok(ug3-ug1,2*pi/i))
      then begin
        s:=0.5*i*r*r*sin(2*pi/i);
        writeln(s:0:10);
        break;
      end;
end.