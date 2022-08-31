{$R+,S+,Q+,I+,O-}
var
  i,n: longint;
  a: array [0..55] of int64;
begin
  read(a[0],a[1],n);
  for i:=2 to n do a[i]:=a[i-1]+a[i-2];
  writeln(a[n]);
end.