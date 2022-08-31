var n,x,y,i:integer;
a,b:array [1..100] of integer;
begin
readln(n);
for i:=1 to 100 do
  begin
  a[i]:=0;
  b[i]:=0;
  end;
for i:=1 to n do
  begin
  readln(x,y);
  a[x]+=1;
  b[y]+=1;
  end;
x:=0;
for i:=1 to 100 do
  begin
  x+=a[i]*b[i];
  end;
writeln(x);
end.