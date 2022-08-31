var n,i,j,k,m,x,y,s,z,p,t:integer;
c:array [1..50] of integer;
a:array [1..50,1..50] of integer;
b:array [1..30000] of integer;
begin
readln(n);
m:=0;
s:=0;
for i:=1 to 50 do
begin
for j:=1 to 50 do a[i,j]:=0;
end;
for i:=1 to n do
begin
read(c[i]);
s:=s+c[i];
end;
for i:=1 to n do
begin
for j:=1 to c[i] do
read(a[i,j]);
end;
x:=n;
y:=c[n];
for k:=s downto 1 do
begin
for i:=1 to n do
begin
for j:=1 to c[i] do
begin
if a[i,j]=k then
begin
p:=i;
t:=j;
break;
end;
end;
end;
if (p<>x) or (t<>y) then
begin
z:=a[x,y];
a[x,y]:=a[p,t];
a[p,t]:=z;
b[4*m+1]:=x;
b[4*m+2]:=y;
b[4*m+3]:=p;
b[4*m+4]:=t;
m:=m+1;
end;
y:=y-1;
if y=0 then
begin
x:=x-1;
y:=c[x];
end;
end;
writeln(m);
for i:=1 to m do
begin
writeln(b[4*i-3],' ',b[4*i-2],' ',b[4*i-1],' ',b[4*i]);
end;
end.