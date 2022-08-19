var i,j,s,n,z:integer;
a,b:array [1..1000] of integer;
begin
readln(s,n);
for i:=1 to n do
readln(a[i],b[i]);
for i:=1 to n-1 do
begin
for j:=1 to n-i do
begin
if a[j]>a[j+1] then
begin
z:=a[j];
a[j]:=a[j+1];
a[j+1]:=z;
z:=b[j];
b[j]:=b[j+1];
b[j+1]:=z;
end;
end;
end;
z:=0;
for i:=1 to n do
begin
if s>a[i] then s:=s+b[i] else z:=1;
end;
if z=0 then writeln('YES') else writeln('NO');
end.