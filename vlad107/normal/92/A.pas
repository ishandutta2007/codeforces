var
  m,n,i:longint;
  a:array[0..100500]of longint;

begin
  read(n,m);
  for i:=1 to n do a[i]:=i;
  i:=1;
  while (m>=a[i])do begin
    dec(m,a[i]);
    inc(i);
    if (i>n)then i:=1;
  end;
  writeln(m);
end.