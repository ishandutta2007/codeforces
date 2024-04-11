var i,j,p,n,k:integer;
ans:int64;
a:array [1..2001000] of int64;
b:array [0..12] of int64;

procedure qsort(x,y:integer);
var z,m:int64;
i,j:integer;
begin
if x>=y then exit;
i:=x;
j:=x+random(y-x+1);
m:=a[j];
j:=y;
while i<=j do
  begin
  while a[i]>m do i+=1;
  while a[j]<m do j-=1;
  if i<=j then
    begin
    z:=a[i];
    a[i]:=a[j];
    a[j]:=z;
    i+=1;
    j-=1;
    end;
  end;
qsort(x,j);
qsort(i,y);
end;

begin
readln(p);
b[0]:=1;
for i:=1 to 12 do b[i]:=b[i-1]*4;
n:=0;
while b[n]<p do n+=1;
for i:=1 to p do read(a[i]);
qsort(1,p);
ans:=0;
for i:=0 to n do
  begin
  for j:=1 to b[i] do ans+=a[j];
  end;
writeln(ans);
end.