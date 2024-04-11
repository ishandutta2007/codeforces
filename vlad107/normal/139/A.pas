var
  n,i,x:longint;
  a:array[0..500500]of longint;

begin
  read(n);
  for i:=1 to 7 do read(a[i]);
  x:=1;
  while (true)do begin
    if (a[x]>=n)then begin
      writeln(x);
      exit;
    end;
    dec(n,a[x]);
    inc(x);
    if (x>7)then dec(x,7);
  end;
end.