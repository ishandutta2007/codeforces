var n,i,a,t:integer;
b,c:array [1..100] of integer;
begin
readln(n);
readln(a);
t:=1;
for i:=1 to n do
begin
readln(b[i],c[i]);
if (b[i]=a) or (b[i]=7-a) or (c[i]=a) or (c[i]=7-a) then t:=0;
end;
if t=1 then writeln('YES') else writeln('NO');
end.