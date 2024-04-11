var
  p:array[0..5]of longint;
  k:array[0..5]of int64;
  a:array[0..500500]of longint;
  i,j,n:longint;
  sum,cr:int64;

begin
  read(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to 5 do read(p[i]);
  for i:=1 to 5 do k[i]:=0;
  sum:=0;
  for i:=1 to n do begin
    inc(sum,a[i]);
    for j:=5 downto 1 do begin
      cr:=sum div p[j];
      sum:=sum-cr*p[j];
      k[j]:=k[j]+cr;
    end;
  end;
  for i:=1 to 5 do write(k[i],' ');
  writeln;
  writeln(sum);
end.