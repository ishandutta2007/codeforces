uses
  math;

const
  eps=1e-8;
  inf=1e9;

var
  d3,d1,d2,a,b,c,tmp,ans,x01,y01,x02,y02,ta,ox,oy,kt,t,xp,yp,vp,x,y,v,r,rv,lt,rt:extended;
  it:longint;
  
  function dist(x1,y1,x2,y2:extended):extended;
    begin
      dist:=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    end;
    
  function inseg(x,y,x1,y1,x2,y2:extended):boolean;
    begin
      inseg:=abs(dist(x,y,x1,y1)+dist(x,y,x2,y2)-dist(x1,y1,x2,y2))<eps;
    end;
    
  procedure cross(a,b,c,r:extended;var x01,y01,x02,y02:extended);
    var
      dd,x00,y00,d:extended;
      
    begin
      d:=sqrt(a*a+b*b);
      a:=a/d;b:=b/d;c:=c/d;
      d:=abs(c);
      if (d+eps>r)then begin
        x01:=inf;y01:=inf;
        x02:=inf;y02:=inf;
        exit;
      end;
      dd:=r*r-d*d;
      if (abs(dd)<eps)then dd:=0;
      dd:=sqrt(dd);
      x00:=-a*c;
      y00:=-b*c;
      x01:=x00-b*dd;
      y01:=y00+a*dd;
      x02:=x00+b*dd;
      y02:=y00-a*dd;
    end;

begin
  {cross(1,-1,0,2,x01,y01,x02,y02);
  writeln(x01:0:10,' ',y01:0:10,' ',x02:0:10,' ',y02:0:10);
  exit;}
  read(xp,yp,vp);
  read(x,y,v,r);
  rv:=sqrt(xp*xp+yp*yp);
  lt:=0;rt:=1e9;
  for it:=1 to 1000 do begin
    t:=(lt+rt)/2;
    kt:=t*vp*180/(PI*rv);
    kt:=kt*PI/180;
    tmp:=arctan2(yp,xp);
    kt:=kt+tmp;
    ox:=rv*cos(kt);
    oy:=rv*sin(kt);
    if (abs(ox)<eps)then ox:=0;
    if (abs(oy)<eps)then oy:=0;
    a:=oy-y;
    b:=x-ox;
    c:=-a*x-b*y;
    cross(a,b,c,r,x01,y01,x02,y02);
    if (not inseg(x01,y01,x,y,ox,oy))or
       (not inseg(x02,y02,x,y,ox,oy))
         then ans:=dist(x,y,ox,oy)
         else begin
           d1:=sqrt(x*x+y*y);
           d2:=sqrt(ox*ox+oy*oy);
           d3:=dist(x,y,ox,oy);
           ta:=arccos((d1*d1+d2*d2-d3*d3)/(2*d1*d2));
           ta:=ta-(arccos(r/d1)+arccos(r/d2));
           while (ta<-eps)do ta:=ta+2*PI;
           if (2*PI-ta<ta)then ta:=2*PI-ta;
           ta:=ta*360/(2*PI);
           ans:=2*PI*r*ta/360;
           ans:=ans+sqrt(d1*d1-r*r)+sqrt(d2*d2-r*r);
         end;
    if (ans/v<t+eps)
      then rt:=t
      else lt:=t;
  end;
  writeln(t:0:10);
end.