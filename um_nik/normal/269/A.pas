var n,i,j,p,q:integer;
s:array [0..20] of int64;
a,k:array [1..100100] of int64;

procedure qsort(x,y:integer);
var i,j,r:integer;
m,z:int64;
begin
if x<y then
  begin
  i:=x;
  j:=y;
  r:=random(y-x+1);
  m:=k[r+x];
  while i<=j do
    begin
    while k[i]<m do i+=1;
    while k[j]>m do j-=1;
    if i<=j then
      begin
      z:=k[i];
      k[i]:=k[j];
      k[j]:=z;
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
end;

begin
readln(n);
for i:=1 to n do
  readln(k[i],a[i]);
s[0]:=1;
for i:=1 to 20 do
  s[i]:=4*s[i-1];
qsort(1,n);
for i:=1 to n-1 do
  begin
  p:=k[i+1]-k[i];
  if p>20 then q:=1 else q:=((a[i]-1) div s[p])+1;
  if q>a[i+1] then a[i+1]:=q;
  end;
if a[n]=1 then p:=1 else
  begin
  for i:=1 to 20 do
    begin
    if s[i]>=a[n] then
      begin
      p:=i;
      break;
      end;
    end;
  end;
writeln(k[n]+p);
end.