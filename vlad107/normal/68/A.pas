var
  a,b,m,p,i,res:longint;
begin
  m:=10011;
  for i:=1 to 4 do begin
    read(p);
    if (p<m)then m:=p;
  end;
  read(a,b);
  res:=0;
  for i:=a to b do
    if (i<m)then inc(res);
  writeln(res);
end.