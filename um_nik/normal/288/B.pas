var n,k,ans:int64;
i,j:integer;
a:array [1..8,1..8] of int64;
begin
readln(n,k);
for i:=1 to 8 do
  for j:=1 to 8 do a[i,j]:=0;
a[1,1]:=k;
for i:=2 to k do
  begin
  for j:=1 to i-1 do
    begin
    a[i,i]+=a[i-1,j]*j;
    a[i,j]+=a[i-1,j]*(k-i);
    end;
  end;
ans:=a[k,k];
for i:=k+1 to n do
  ans:=(ans*(n-k)) mod 1000000007;
writeln(ans);
end.