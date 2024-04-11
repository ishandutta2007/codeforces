var
  i,n:longint;
  sx,sy,x,y,res:int64;
begin
  read(n);
  for i:=1 to n do begin
    read(x,y);
    inc(res,(n-1)*(x*x+y*y)-2*(x*sx+y*sy));
    inc(sx,x);inc(sy,y);
  end;
  writeln(res);
end.