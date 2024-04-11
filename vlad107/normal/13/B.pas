const
  eps=1e-5;
type
  TCover=record
    x1,y1,x2,y2:extended;
  end;
var
  tt:longint;
  tmp:extended;
  a,b,c:TCover;
  ok:boolean;
  function incover(x,y:extended;a:TCover):boolean;
    begin
      incover:=false;
      if (abs((a.y2-a.y1)*(x-a.x1)+(a.x1-a.x2)*(y-a.y1))>eps)then exit;
      if (a.x1-a.x2>eps)then begin
        tmp:=a.x1;a.x1:=a.x2;a.x2:=tmp;
      end;
      if (a.x1-x>eps)or(x-a.x2>eps)then exit;
      if (a.y1>a.y2)then begin
        tmp:=a.y1;a.y1:=a.y2;a.y2:=tmp;
      end;
      if (a.y1-y>eps)or(y-a.y2>eps)then exit;
      incover:=true;
    end;
  function solve(a,b,c:TCover):boolean;
    var
      ug,d1,d2,d3:extended;
    begin
      if (a.x1=b.x2)and(a.y1=b.y2)then begin
        tmp:=b.x1;b.x1:=b.x2;b.x2:=tmp;
        tmp:=b.y1;b.y1:=b.y2;b.y2:=tmp;
      end else
      if (a.x2=b.x2)and(a.y2=b.y2)then begin
        tmp:=b.x1;b.x1:=b.x2;b.x2:=tmp;
        tmp:=b.y1;b.y1:=b.y2;b.y2:=tmp;
        tmp:=a.x1;a.x1:=a.x2;a.x2:=tmp;
        tmp:=a.y1;a.y1:=a.y2;a.y2:=tmp;
      end else
      if (a.x2=b.x1)and(a.y2=b.y1)then begin
        tmp:=a.x1;a.x1:=a.x2;a.x2:=tmp;
        tmp:=a.y1;a.y1:=a.y2;a.y2:=tmp;
      end;
      solve:=false;
      if (abs(a.x1-b.x1)>=eps)or(abs(a.y1-b.y1)>=eps)then exit;
      if (incover(c.x2,c.y2,a))then begin
        tmp:=c.x1;c.x1:=c.x2;c.x2:=tmp;
        tmp:=c.y1;c.y1:=c.y2;c.y2:=tmp;
      end;
      if (not incover(c.x1,c.y1,a))or(not incover(c.x2,c.y2,b))then exit;
      d1:=sqrt((a.x2-a.x1)*(a.x2-a.x1)+(a.y2-a.y1)*(a.y2-a.y1));
      d2:=sqrt((b.x2-b.x1)*(b.x2-b.x1)+(b.y2-b.y1)*(b.y2-b.y1));
      d3:=sqrt((b.x2-a.x2)*(b.x2-a.x2)+(b.y2-a.y2)*(b.y2-a.y2));
      ug:=(d1*d1+d2*d2-d3*d3);
      if (ug>=eps+2*d1*d2)or(ug<-eps)then exit;
      d1:=sqrt((a.x1-c.x1)*(a.x1-c.x1)+(a.y1-c.y1)*(a.y1-c.y1));
      d2:=sqrt((a.x2-c.x1)*(a.x2-c.x1)+(a.y2-c.y1)*(a.y2-c.y1));
      if (d2<d1)and(4*d2<d1)then exit;
      if (d1<d2)and(4*d1<d2)then exit;
      d1:=sqrt((b.x1-c.x2)*(b.x1-c.x2)+(b.y1-c.y2)*(b.y1-c.y2));
      d2:=sqrt((b.x2-c.x2)*(b.x2-c.x2)+(b.y2-c.y2)*(b.y2-c.y2));
      if (d2<d1)and(4*d2<d1)then exit;
      if (d1<d2)and(4*d1<d2)then exit;
      solve:=true;
    end;
begin
  read(tt);
  while (tt>0)do begin
    dec(tt);
    read(a.x1,a.y1,a.x2,a.y2);
    read(b.x1,b.y1,b.x2,b.y2);
    read(c.x1,c.y1,c.x2,c.y2);
    ok:=solve(a,b,c)or
        solve(a,c,b)or
        solve(c,b,a);
    if (ok)
      then writeln('YES')
      else writeln('NO');
  end;
end.