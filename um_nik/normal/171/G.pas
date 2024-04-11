var i,n:integer;
a:array [0..20] of int64;
begin
read(a[0],a[1],n);
for i:=2 to n do a[i]:=a[i-1]+a[i-2];
writeln(a[n]);
end.