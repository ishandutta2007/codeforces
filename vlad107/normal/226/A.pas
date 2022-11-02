var
  n,base,res,x:longint;

begin
  read(n,base);
  res:=1;
  x:=3;
  while (n>0)do begin
    if (n and 1=1)
      then res:=int64(res)*x mod base;
    x:=int64(x)*x mod base;
    n:=n shr 1;
  end;
  dec(res);
  if (res<0)then inc(res,base);
  writeln(res);
end.