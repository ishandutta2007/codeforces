var n,i,p,m:integer;
a,b:array [1..100000] of integer;
begin
readln(n);
p:=1;
m:=1;
readln(a[1],b[1]);
for i:=2 to n do
begin
readln(a[i],b[i]);
if (a[i]=a[i-1]) and (b[i]=b[i-1]) then
begin
p:=p+1;
if p>m then m:=p;
end else
begin
p:=1;
end;
end;
writeln(m);
end.