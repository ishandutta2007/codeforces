var i,j,t:integer;
a:array [1..4] of integer;
begin
for i:=1 to 4 do
read(a[i]);
t:=0;
for i:=1 to 3 do
begin
for j:=i+1 to 4 do
begin
if a[i]=a[j] then
begin
t:=t+1;
break;
end;
end;
end;
writeln(t);
end.