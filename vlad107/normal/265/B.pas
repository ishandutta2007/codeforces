var
  res,n,i:longint;
  h:array[0..500500]of longint;

begin
  read(n);
  for i:=1 to n do read(h[i]);
  res:=h[1]+1;
  for i:=2 to n do begin
    inc(res,abs(h[i]-h[i-1])+2);
  end;
  writeln(res);
end.