var
  n,t:longint;
begin
  read(t);
  while (t>0)do begin
    dec(t);read(n);
    if (n<2)then n:=2;
    writeln(n-2);
  end;
end.