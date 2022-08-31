var i,n,q,d:integer;
c,k:int64;
a:array [1..100100] of integer;
b:array [1..100100] of int64;
begin
readln(n,d);
for i:=1 to n do
read(a[i]);
q:=3;
for i:=1 to n-1 do
  begin
  while a[q]-a[i]<=d do
    begin
    q:=q+1;
    if q>n then break;
    end;
  if q>n then
    begin
    q:=i;
    break;
    end else
    begin
    b[i]:=q-1;
    end;
  end;
for i:=q to n-1 do
b[i]:=n;
k:=0;
for i:=1 to n-1 do
  begin
  c:=i;
  k:=k+((b[i]-1-c)*(b[i]-c)) div 2;
  end;
writeln(k);
end.