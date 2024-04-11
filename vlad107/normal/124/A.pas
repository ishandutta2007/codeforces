var
  n,res,l,r:longint;

begin
  read(n,l,r);
  r:=n-r;
  if (l+1>r)then r:=l+1;
  res:=n-r+1;
  if (res<0)then res:=0;
  writeln(res);
end.