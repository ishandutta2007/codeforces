var
  i,j,n:longint;
begin
  read(n);
  i:=1;j:=n;
  while (i<j)do begin
    write(i, ' ',j, ' ');
    inc(i);dec(j);
  end;
  if (i=j)then writeln(i)else writeln;
end.