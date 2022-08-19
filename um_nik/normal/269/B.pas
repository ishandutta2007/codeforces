var m,n,i,j,t:integer;
x:real;
a:array [0..10000] of integer;
b:array [0..10000] of integer;
begin
readln(n,m);
for i:=1 to n do
  readln(a[i],x);
a[0]:=0;
for i:=0 to n do
  begin
  b[i]:=0;
  end;
for i:=1 to n do
  begin
  for j:=0 to i-1 do
    begin
    if (b[i]<=b[j]) and (a[i]>=a[j]) then b[i]:=b[j]+1;
    end;
  end;
t:=0;
for i:=1 to n do
  begin
  if b[i]>t then t:=b[i];
  end;
writeln(n-t);
end.