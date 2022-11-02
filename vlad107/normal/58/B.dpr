var
  x,n,i:longint;
begin
  read(n);
  x:=n;
  write(x);
  for i:=2 to n do begin
    while (x mod i=0)do begin
      x:=x div i;
      write(' ',x);
    end;
  end;
  writeln;
end.