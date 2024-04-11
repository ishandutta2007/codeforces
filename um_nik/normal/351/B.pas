var n,i,j,k,z:integer;
a:array [1..3100] of integer;
begin
readln(n);
for i:=1 to n do read(a[i]);
k:=0;
for i:=1 to n-1 do
  for j:=1 to n-i do
    begin
    if a[j]>a[j+1] then
      begin
      k+=1;
      z:=a[j];
      a[j]:=a[j+1];
      a[j+1]:=z;
      end;
    end;
if k mod 2=0 then writeln(2*k) else writeln(2*k-1);
end.