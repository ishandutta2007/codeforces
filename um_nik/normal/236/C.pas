var a,n:int64;
begin
readln(n);
if n<3 then writeln(n) else
begin
if n mod 2=1 then a:=n*(n-1)*(n-2) else
begin
if n mod 3=0 then a:=(n-1)*(n-2)*(n-3) else a:=n*(n-1)*(n-3);
end;
writeln(a);
end;
end.