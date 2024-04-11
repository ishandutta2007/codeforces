const
  eps=1e-10;

var
  q1,q2:longint;
  x0,y0,q,a3,b3,c3,a1,b1,c1,a2,b2,c2,xp,yp,xv,yv,xw1,yw1,xw2,yw2,xm1,ym1,xm2,ym2:extended;
  
  function dist(x1,y1,x2,y2:extended):extended;
    begin
      dist:=sqrt((y2-y1)*(y2-y1)+(x2-x1)*(x2-x1));
    end;

  function way(x1,y1,x2,y2,x3,y3:extended):longint;
    var
      q:extended;
    begin
      q:=(y2-y1)*(x3-x1)+(x1-x2)*(y3-y1);
      if (q<-eps)then way:=-1 else 
      if (q>eps)then way:=1 else way:=0;
    end;

  function crossing(x1,y1,x2,y2,x3,y3,x4,y4:extended;mirror:boolean):boolean;
    var
      q1,q2,q3,q4:longint;
      tmp:extended;
    begin
      q1:=way(x1,y1,x2,y2,x3,y3);
      q2:=way(x1,y1,x2,y2,x4,y4);
      if (q1=0)and(q2=0)then begin
        if (mirror)then begin
          crossing:=false;
          exit;
        end;
        if (x1=x2)then begin
          tmp:=x1;x1:=y1;y1:=tmp;
          tmp:=x2;x2:=y2;y2:=tmp;
          tmp:=x3;x3:=y3;y3:=tmp;
          tmp:=x4;x4:=y4;y4:=tmp;
        end;
        if (x1>x2)then begin 
          tmp:=x1;x1:=x2;x2:=tmp;
        end;
        if (x3>x4)then begin
          tmp:=x3;x3:=x4;x4:=tmp;
        end;
        if ((x3+eps>=x1)and(x3<=x2+eps))or
            ((x4+eps>=x1)and(x4<=x2+eps))or
            ((x1+eps>=x3)and(x1<=x4+eps))or
            ((x2+eps>=x3)and(x2<=x4+eps))
              then crossing:=true
              else crossing:=false;
        exit;
      end;
      q3:=way(x3,y3,x4,y4,x1,y1);
      q4:=way(x3,y3,x4,y4,x2,y2);
      crossing:=(q1*q2<=0)and(q3*q4<=0)
    end;

  procedure cross(a1,b1,c1,a2,b2,c2:extended;var x0,y0:extended);
    var
      d,dx,dy:extended;
      
    begin
      d:=a1*b2-b1*a2;
      dx:=c1*b2-b1*c2;
      dy:=a1*c2-c1*a2;
      if (abs(d)<eps)then begin
        writeln('NO');
        exit;
      end;
      x0:=-dx/d;
      y0:=-dy/d;
    end;

begin
//  assign(input,'input.txt');reset(input);
//  assign(output,'output.txt');rewrite(output);
  read(xv,yv,xp,yp,xw1,yw1,xw2,yw2,xm1,ym1,xm2,ym2);
  if (not crossing(xv,yv,xp,yp,xw1,yw1,xw2,yw2,false))and(not crossing(xv,yv,xp,yp,xm1,ym1,xm2,ym2,true))
    then begin writeln('YES');exit; end;
  a3:=xm2-xm1;
  b3:=ym2-ym1;
  c3:=-a3*xp-b3*yp;
  a2:=ym2-ym1;
  b2:=xm1-xm2;
  c2:=-a2*xm1-b2*ym1;
  q1:=way(xm1,ym1,xm2,ym2,xv,yv);
  q2:=way(xm1,ym1,xm2,ym2,xp,yp);
  if (q1*q2<=0)then begin
    writeln('NO');
    exit;
  end;
  cross(a2,b2,c2,a3,b3,c3,x0,y0);
  x0:=2*x0-xp;
  y0:=2*y0-yp;
  a1:=yv-y0;
  b1:=x0-xv;
  c1:=-a1*x0-b1*y0;
  cross(a1,b1,c1,a2,b2,c2,x0,y0);
  q:=abs(dist(x0,y0,xm1,ym1)+dist(x0,y0,xm2,ym2)-dist(xm1,ym1,xm2,ym2));
  if (abs(q)<eps)and(not crossing(xv,yv,x0,y0,xw1,yw1,xw2,yw2,false))and(not crossing(xp,yp,x0,y0,xw1,yw1,xw2,yw2,false))
    then writeln('YES') else writeln('NO');  
end.