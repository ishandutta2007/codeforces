{$r-,q-,s-,i-,o+}
const
  eps=1e-9;
  inf=1e18;

var
  tt:longint;
  x1,y1,x2,y2,x3,y3,x4,y4:extended;
  found:boolean;
  
  function way(x1,y1,x2,y2,x3,y3:extended):longint;
    var
      qqq:extended;
    begin
      qqq:=(y2-y1)*(x3-x1)+(x1-x2)*(y3-y1);
      if (qqq<-eps)then way:=-1 else 
      if (abs(qqq)<eps)then way:=0 else
      way:=1;
    end;

  procedure cross(a1,b1,c1,a2,b2,c2:extended;var x0,y0:extended);
    var
      d,dx,dy:extended;
    begin
      d:=a1*b2-b1*a2;
      dx:=c1*b2-b1*c2;
      dy:=a1*c2-c1*a2;
      if (abs(d)<eps)then begin
        x0:=inf;y0:=inf;
        exit;
      end;
      x0:=-dx/d;
      y0:=-dy/d;
    end;
  
  procedure mp(x1,y1,x2,y2:extended;var x3,y3:extended);
    begin
      x3:=2*x2-x1;
      y3:=2*y2-y1;
    end;
    
  procedure perp(x1,y1,x2,y2:extended;var a,b,c:extended);
    begin
      a:=x2-x1;
      b:=y2-y1;
      c:=-a*(x1+x2)/2-b*(y1+y2)/2;
    end;
    
  procedure calc(x1,y1,x2,y2,x3,y3:extended;var x0,y0:Extended);
    var
      a1,b1,c1,a2,b2,c2:extended;
    begin
      perp(x1,y1,x2,y2,a1,b1,c1);
      perp(x2,y2,x3,y3,a2,b2,c2);
      cross(a1,b1,c1,a2,b2,c2,x0,y0);
    end;

  procedure check(xk,yk,xl,yl,xm,ym:extended);
    var
      xk2,yk2,x1,y1,x2,y2,x3,y3,x4,y4:extended;
      q1,q2,q3,q4:longint;
    begin
      if (found)then exit;
      mp(xk,yk,xl,yl,xk2,yk2);
      calc(xk2,yk2,xl,yl,xm,ym,x1,y1);
      if (x1>inf-10)then exit;
      mp(x1,y1,xm,ym,x2,y2);
      mp(x1,y1,xl,yl,x4,y4);
      mp(x4,y4,xk,yk,x3,y3);
      q1:=way(x1,y1,x2,y2,x3,y3);
      q2:=way(x2,y2,x3,y3,x4,y4);
      q3:=way(x3,y3,x4,y4,x1,y1);
      q4:=way(x4,y4,x1,y1,x2,y2);
      if (q1<>q2)or(q1<>q3)or(q1<>q4)then exit;
      found:=true;
      writeln('YES');
      writeln(x1:0:10,' ',y1:0:10,' ',x2:0:10,' ',y2:0:10,' ',
              x3:0:10,' ',y3:0:10,' ',x4:0:10,' ',y4:0:10);
    end;

begin
  read(tt);
  while (tt>0)do begin
    dec(tt);
    read(x1,y1,x2,y2,x3,y3);
    found:=false;
    check(x1,y1,x2,y2,x3,y3);
    check(x1,y1,x3,y3,x2,y2);
    check(x2,y2,x1,y1,x3,y3);
    check(x2,y2,x3,y3,x1,y1);
    check(x3,y3,x1,y1,x2,y2);
    check(x3,y3,x2,y2,x1,y1);
    if (not found)then begin writeln('NO');writeln;end;
  end;
end.