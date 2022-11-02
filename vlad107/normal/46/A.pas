var
  q,x,n,i,k:longint;

begin
  read(n);
  x:=1;
  k:=0;
  q:=0;
  for i:=1 to n do begin
    inc(x,k);
    while (x>n) do dec(x,n);
    inc(k);
    if (i>1)then write(x, ' ');
  end;
  writeln;
end.