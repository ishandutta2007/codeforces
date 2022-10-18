const e = round(1e9)+7;
var i, j, k, m, n, ans: longint;
    f: array [1..2000, 1..2000] of longint;
begin
 readln(m, n);
 for j:=1 to m do f[1, j]:=1;
 for i:=1 to n-1 do
  for j:=1 to m do
   for k:=1 to m div j do
    f[i+1, j*k]:=(f[i+1, j*k]+f[i, j]) mod e;
 
 ans:=0;
 for j:=1 to m do ans:=(ans+f[n, j]) mod e;
 writeln(ans);
end.