var
  n,k,d,min,s:uint64;
  i:longint;
  a:array[1..100000]of uint64;

begin
  read(n,k);
  read(a[1]);
  min:=a[1];
  d:=a[1] mod k;
  for i:=2 to n do
    begin
      read(a[i]);
      if d<>(a[i] mod k) then
        begin
          writeln(-1);
          exit
        end;
      if min>a[i] then
        min:=a[i]
    end;
  s:=0;
  for i:=1 to n do
    inc(s,(a[i]-min) div k);
  writeln(s)
end.