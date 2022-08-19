var n,i,a,b,c,x,k:integer;
begin
readln(n);
k:=0;
for i:=1 to n do
begin
readln(a,b,c);
x:=a+b+c;
if x>1 then k:=k+1;
end;
writeln(k);
end.