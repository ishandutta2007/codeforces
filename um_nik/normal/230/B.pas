var i,n,j,t:integer;
a:int64;
begin
readln(n);
for i:=1 to n do
begin
t:=0;
read(a);
if a=1 then t:=1;
if sqrt(a)-trunc(sqrt(a))>0 then t:=1 else a:=trunc(sqrt(a));
if t=0 then
begin
for j:=2 to trunc(sqrt(a)) do
if a mod j=0 then t:=1;
end;
if t=0 then writeln('YES') else writeln('NO');
end;
end.