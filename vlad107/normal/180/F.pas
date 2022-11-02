var
  n,i:longint;
  a,b,c:array[0..500500]of longint;

begin
  read(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do read(b[i]);
  for i:=1 to n do c[a[i]]:=b[i];
  for i:=1 to n do write(c[i],' ');
  writeln;
end.