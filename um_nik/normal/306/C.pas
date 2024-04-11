const mm=1000000009;
var n,w,b,ans,k:int64;
i,j:integer;
c:array [0..8002,0..4002] of int64;
begin
for i:=0 to 8002 do
  for j:=0 to 4002 do
    if j>0 then c[i,j]:=0 else c[i,j]:=1;
for i:=1 to 8002 do
  for j:=1 to 4002 do
    c[i,j]:=(c[i-1,j]+c[i-1,j-1]) mod mm;
read(n,w,b);
ans:=w-1;
for i:=2 to w do
  begin
  k:=i;
  ans:=(ans*k) mod mm;
  end;
for i:=2 to b do
  begin
  k:=i;
  ans:=(ans*k) mod mm;
  end;
ans:=(ans*c[w+b-3,n-3]) mod mm;
writeln(ans);
end.