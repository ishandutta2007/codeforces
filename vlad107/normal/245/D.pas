var
  n,i,j,x:longint;
  a:array[0..500500]of longint;
begin
  read(n);
  for i:=1 to n do a[i]:=0;
  for i:=1 to n do for j:=1 to n do begin
    read(x);
    if (x=-1)then continue;
    a[i]:=a[i] or x;
  end;
  for i:=1 to n do write(a[i],' ');
  writeln;
end.