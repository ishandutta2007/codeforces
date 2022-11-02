var
  max,n,x,i:longint;
  a:array[1..100]of longint;
begin
  read(n);max:=0;
  for i:=1 to n do begin
    read(x);
    inc(a[x]);
    if (a[x]>max)then max:=a[x];
  end;
  writeln(n-max);
end.