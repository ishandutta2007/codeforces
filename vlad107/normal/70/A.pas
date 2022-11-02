var
  res,n,i:longint;
begin
  read(n);
  res:=1;
  for i:=1 to n-1 do res:=res*3 mod 1000003;
  writeln(res);
end.