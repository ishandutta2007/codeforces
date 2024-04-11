var
  i,x,n:longint;
  a:array[1..1000000]of boolean;
begin
  read(n);
  for i:=1 to n do begin
    read(x);
    a[x]:=true;
  end;
  i:=1;
  while (a[i])do inc(i);
  writeln(i);
end.