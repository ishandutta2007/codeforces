var i,j,k,t,x,y,x0,y0,na,nb,ma,mb:integer;
a,b:array [1..50,1..50] of char;
begin
readln(na,ma);
for i:=1 to na do
begin
for j:=1 to ma do
read(a[i,j]);
readln();
end;
readln(nb,mb);
for i:=1 to nb do
begin
for j:=1 to mb do
read(b[i,j]);
readln();
end;
x0:=0;
y0:=0;
k:=0;
for x:=0-nb-na-1 to nb+1 do
begin
for y:=0-mb-ma-1 to mb+1 do
begin
t:=0;
for i:=1 to na do
begin
for j:=1 to ma do
begin
if (i+x>=1) and (i+x<=nb) and (j+y>=1) and (j+y<=mb) then
begin
if (a[i,j]='1') and (b[i+x,j+y]='1') then t:=t+1;
end;
end;
end;
if t>k then
begin
k:=t;
x0:=x;
y0:=y;
end;
end;
end;
writeln(x0,' ',y0);
end.