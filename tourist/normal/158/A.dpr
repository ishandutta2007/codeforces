{$R-,S-,Q-,I-,O+}
var
  n,k,i,ans: longint;
  a: array [0..11111] of longint;
begin
  read(n,k);
  for i:=1 to n do read(a[i]);
  ans:=0;
  for i:=1 to n do
    if (a[i] > 0) and (a[i] >= a[k]) then inc(ans);
  writeln(ans);
end.