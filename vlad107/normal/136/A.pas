var
  a:array[0..500500]of longint;
  n,i,x:longint;

begin
  read(n);
  for i:=1 to n do begin
    read(x);
    a[x]:=i;
  end;
  for i:=1 to n do write(a[i],' ');
  writeln;
end.