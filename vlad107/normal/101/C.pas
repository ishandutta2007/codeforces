{$r-,q-,s-,i-,o+}
var
  dx,dy,d,a1,a2,b1,b2,c1,c2,xa,ya,xb,yb,xc,yc:int64;

  procedure check(xd,yd:int64);
    begin
      a1:=xc;b1:=-yc;c1:=xd;
      a2:=yc;b2:=xc;c2:=yd;
      if (a1=0)and(b1=0)and(c1<>0)then exit;
      if (a2=0)and(b2=0)and(c2<>0)then exit;
      d:=a1*b2-b1*a2;
      dx:=a1*c2-c1*a2;
      dy:=c1*b2-b1*c2;
      if (d=0)and(dx=0)and(dy=0)then begin
        writeln('YES');
        halt(0);
      end;
      if (d=0)then exit;
      if (dx mod d=0)and(dy mod d=0)then begin
        writeln('YES');
        halt(0);
      end;
    end;

begin
  read(xa,ya);
  read(xb,yb);
  read(xc,yc);
  check(xb-xa,yb-ya);
  check(xb+xa,yb+ya);
  check(xb+ya,yb-xa);
  check(xb-ya,yb+xa);
  writeln('NO');
end.