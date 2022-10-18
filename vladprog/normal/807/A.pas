const
  inf=10000;

var
  n,i:longint;
  a,b:array[0..1000]of longint;

begin
  read(n);
  a[0]:=inf;
  for i:=1 to n do
    read(a[i],b[i]);
  for i:=1 to n do
    if a[i]<>b[i] then
      begin
        writeln('rated');
        halt
      end;
  for i:=1 to n do
    if a[i]>a[i-1] then
      begin
        writeln('unrated');
        halt
      end;
  writeln('maybe');
end.