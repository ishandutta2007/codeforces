const pi=3.14159265358979323846;
var i,n,b,c:integer;
x,y,z:real;
a:array [1..101000] of real;

procedure qsort(x,y:integer);
var i,j:integer;
z,m:real;
begin
if y>x then
  begin
  i:=x;
  j:=y;
  m:=a[(i+j) div 2];
  while i<=j do
    begin
    while a[i]<m do i:=i+1;
    while a[j]>m do j:=j-1;
    if i<=j then
      begin
      z:=a[i];
      a[i]:=a[j];
      a[j]:=z;
      i:=i+1;
      j:=j-1;
      end;
    end;
  qsort(i,y);
  qsort(x,j);
  end;
end;

begin
readln(n);
for i:=1 to n do
  begin
  readln(b,c);
  x:=b;
  y:=c;
  if x<>0 then a[i]:=arctan(y/x) else
      begin
      if y>0 then a[i]:=pi/2 else a[i]:=-pi/2;
      end;
  if x<0 then
    begin
    if a[i]>0 then a[i]:=a[i]-pi else a[i]:=a[i]+pi;
    end;
  end;
qsort(1,n);
z:=2*pi+a[1]-a[n];
for i:=1 to n-1 do
  begin
  if z<a[i+1]-a[i] then z:=a[i+1]-a[i];
  end;
z:=2*pi-z;
z:=180*z/pi;
writeln(z:20:10);
end.