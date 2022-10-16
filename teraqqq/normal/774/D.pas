var
n, l,j,  i, x, r, t:integer;
f:boolean;
a, b, c: array [1..100000] of integer;
begin
f:=TRUE;
read(n);
read(l);
read(r);
for i:= 1 to n do
read(a[i]);
for i:= 1 to n do
read(b[i]);
for i := l to r do
    c[a[i]] += 1;
for i := l to r do
    c[b[i]] -= 1;
for i:= l to r do
    if c[i] <> 0 then f := FALSE;
for i:=1 to l-1 do
    if(a[i]<>b[i]) then f:=FALSE;
for i:=r+1 to n do
    if(a[i]<>b[i]) then f:=FALSE;
if f then writeln('TRUTH') else writeln('LIE');
end.