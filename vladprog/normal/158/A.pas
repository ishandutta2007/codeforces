var
  n,k,i:longint;
  a:array[1..50]of longint;

begin
  read(n,k);
  for i:=1 to n do
    read(a[i]);
  for i:=1 to n do
    if (a[i]<a[k])or(a[i]<=0) then
      begin
        writeln(i-1);
        halt
      end;
  writeln(n)
end.