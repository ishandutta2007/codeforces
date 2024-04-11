var s,k,i,j,t,m:integer;
a,b:array [1..100000] of int64;
begin
readln(s,k);
a[1]:=0;
a[2]:=1;
m:=0;
for i:=3 to k+1 do
begin
a[i]:=0;
for j:=1 to i-1 do
begin
a[i]:=a[i]+a[j];
end;
if a[i]>s then
begin
m:=i;
break;
end;
end;
if m=0 then
begin
for i:=k+2 to 1000000 do
begin
a[i]:=0;
for j:=i-k to i-1 do
begin
a[i]:=a[i]+a[j];
end;
if a[i]>s then
begin
m:=i;
break;
end;
end;
end;
t:=2;
b[1]:=0;
b[2]:=a[m-1];
j:=3;
s:=s-b[2];
while s>0 do
begin
for i:=2 to m do
begin
if s<a[i] then
begin
m:=i;
b[j]:=a[i-1];
s:=s-b[j];
t:=t+1;
j:=j+1;
break;
end;
end;
end;
writeln(t);
for i:=1 to t do
write(b[i],' ');
end.