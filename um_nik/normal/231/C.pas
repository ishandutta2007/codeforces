var n,l,g,m,p:integer;
a,c:array [0..100000] of int64;
procedure qsort(x,y:integer);
var i,j,m,tmp:integer;
begin
if y-x>0 then
begin
i:=x;
j:=y;
m:=a[(i+j) div 2];
while i<=j do
begin
while a[i]<m do i:=i+1;
while a[j]>m do j:=j-1;
if (i<=j) then
begin
tmp:=a[i];
a[i]:=a[j];
a[j]:=tmp;
i:=i+1;
j:=j-1;
end;
end;
if x<j then qsort(x,j);
if i<y then qsort(i,y);
end;
end;
begin
readln(n,l);
for g:=1 to n do
read(a[g]);
qsort(1,n);
c[0]:=0;
for g:=1 to n do
begin
//write('!! ',a[g],' ');
c[g]:=c[g-1]+a[g];
end;
m:=1;
p:=a[1];
for g:=2 to n do
begin
if c[g]-c[g-(m+1)]>=(m+1)*a[g]-l then
begin
m:=m+1;
p:=a[g];
end;
end;
writeln(m,' ',p);
end.