var x,y,n,m,i,j:integer;
k,ans:int64;
a,b:array [1..300000] of int64;

procedure qsorta(x,y:integer);
var i,j:integer;
m,z:int64;
begin
if y>x then
  begin
  i:=x;
  j:=random(y-x+1);
  m:=a[i+j];
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
  qsorta(x,j);
  qsorta(i,y);
  end;
end;

procedure qsortb(x,y:integer);
var i,j:integer;
m,z:int64;
begin
if y>x then
  begin
  i:=x;
  j:=random(y-x+1);
  m:=b[i+j];
  j:=y;
  while i<=j do
    begin
    while b[i]>m do i+=1;
    while b[j]<m do j-=1;
    if i<=j then
      begin
      z:=b[i];
      b[i]:=b[j];
      b[j]:=z;
      i+=1;
      j-=1;
      end;
    end;
  qsortb(x,j);
  qsortb(i,y);
  end;
end;

begin
readln(n,m);
for i:=1 to n do
  begin
  read(a[i]);
  b[i]:=0;
  end;
for i:=1 to m do
  begin
  read(x,y);
  b[x]+=1;
  b[y+1]-=1;
  end;
x:=0;
for i:=1 to n do
  begin
  x+=b[i];
  b[i]:=x;
  end;
qsorta(1,n);
qsortb(1,n);
ans:=0;
for i:=1 to n do ans+=a[i]*b[i];
writeln(ans);
end.