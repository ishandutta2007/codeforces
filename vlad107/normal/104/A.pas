var
  res,n,i:longint;

begin
  read(n);
  res:=0;
  for i:=2 to 10 do
    if (10+i=n)then inc(res);
  if (11=n)then inc(res);
  if (21=n)then inc(res);
  res:=res*4;
  if (n=20)then inc(res,11);
  writeln(res);
end.