var n,i,k,p,q,j:integer;
a,b:array [1..200000] of int64;
ans,m:int64;

procedure qsort(x,y:integer);
var i,j:integer;
m,z:int64;
begin
if y>x then
  begin
  i:=x;
  j:=random(y-x+1);
  m:=a[j+x];
  j:=y;
  while i<=j do
    begin
    while a[i]<m do i+=1;
    while a[j]>m do j-=1;
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
end;

begin
readln(n);
for i:=1 to n do read(a[i]);
k:=0;
for i:=1 to n do
  begin
  read(a[n+i]);
  if a[i]=a[n+i] then k+=1;
  end;
qsort(1,2*n);
p:=0;
q:=1;
for i:=1 to 2*n-1 do
  begin
  if a[i]=a[i+1] then q+=1 else
    begin
    if q>1 then
      begin
      p+=1;
      b[p]:=q;
      q:=1;
      end;
    end;
  end;
if q>1 then
  begin
  p+=1;
  b[p]:=q;
  end;
readln(m);
ans:=1;
//writeln(k,' ',p);
for i:=1 to p do
  begin
  for j:=2 to b[i] do
    begin
    ans:=ans*j;
    while (ans mod 2=0) and (k>0) do
      begin
      ans:=ans shr 1;
      k-=1;
      end;
    ans:=ans mod m;
    end;
  if ans=0 then break;
  end;
writeln(ans);
end.