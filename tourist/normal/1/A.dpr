{$R+,S+,Q+,I+,O-}
var
  n,m,a: int64;
begin
  read(n,m,a);
  writeln(((n+a-1) div a)*((m+a-1) div a));
end.