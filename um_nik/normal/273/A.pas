var n,m,i:integer;
w,h,x:int64;
a:array [1..100000] of int64;
begin
readln(n);
for i:=1 to n do read(a[i]);
readln(m);
for i:=1 to m do
  begin
  readln(w,h);
  if a[w]>a[1] then x:=a[w] else x:=a[1];
  writeln(x);
  a[1]:=x+h;
  end;
end.