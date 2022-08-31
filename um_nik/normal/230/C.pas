var i,j,n,m,k,p,s,t,m1,m2,g,h:integer;
a:array [1..100,1..10000] of char;
b:array [1..100,1..10000] of integer;
begin
readln(n,m);
s:=0;
for i:=1 to n do
begin
for j:=1 to m do
read(a[i,j]);
readln();
p:=0;
m1:=0;
for j:=1 to m do
begin
if a[i,j]='1' then
begin
b[i,j]:=0;
g:=p;
p:=j;
if m1=0 then m1:=p;
for h:=g+1 to p-1 do
begin
if g=0 then b[i,h]:=p-h else
begin
if h-g>p-h then b[i,h]:=p-h else b[i,h]:=h-g;
end;
end;
end;
end;
for j:=p+1 to m do
b[i,j]:=j-p;
m2:=p;
for j:=1 to m1-1 do
begin
if b[i,j]>m+j-m2 then b[i,j]:=m+j-m2;
end;
for j:=m2+1 to m do
begin
if b[i,j]>m1+m-j then b[i,j]:=m1+m-j;
end;
if p=0 then s:=-1;
end;
if s=-1 then writeln(s) else
begin
k:=99999999;
for i:=1 to m do
begin
s:=0;
for j:=1 to n do
s:=s+b[j,i];
if s<k then
begin
k:=s;
t:=i;
end; 
end;
writeln(k);
end;
end.