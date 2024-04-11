var
  dx,dy,tt,n,m,x1,y1,x2,y2:longint;
  s:int64;
begin
  read(tt);
  while (tt>0)do begin
    dec(tt);
    read(n,m,x1,y1,x2,y2);
    dx:=abs(x1-x2);
    dy:=abs(y1-y2);
    s:=int64(n-dx)*(m-dy)*2;
    if (1+dx<=n-dx)and(1+dy<=m-dy)
      then s:=s-int64(n-2*dx)*(m-2*dy);
    writeln(int64(n)*m-s);
  end;
end.