var m,n,i,e:integer;
a,b:int64;
c:array [1..100000] of int64;
begin
readln(n);
for i:=1 to n do
begin
read(e);
c[e]:=i;
end;
readln(m);
a:=0;
b:=0;
for i:=1 to m do
begin
read(e);
a:=a+c[e];
b:=b+n+1-c[e];
end;
writeln(a,' ',b);
end.