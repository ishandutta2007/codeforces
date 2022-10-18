const
  inf=200000;

var
  n,i,k:longint;
  a,b,c:array[1..200000]of longint;

begin
  read(n);
  for i:=1 to n do
    read(a[i]);
  k:=inf;
  for i:=1 to n do
    begin
      if a[i]=0
        then k:=0
        else inc(k);
      b[i]:=k
    end;
  k:=inf;
  for i:=n downto 1 do
    begin
      if a[i]=0
        then k:=0
        else inc(k);
      c[i]:=k
    end;
  for i:=1 to n do
    if b[i]<c[i]
      then write(b[i],' ')
      else write(c[i],' ')
end.