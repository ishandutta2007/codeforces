{$R+,S+,Q+,I+,O-}
var
  x,i,n: longint;
begin
  read(n);
  x:=1;
  for i:=2 to n do x:=x+(i-1)*12;
  writeln(x);
end.