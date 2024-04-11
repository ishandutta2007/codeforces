var
  n:int64;
  k:longint;

begin
  read(n);
  k:=0;
  while (n>0)do begin
    if (n mod 10=4)or(n mod 10=7)then inc(k);
    n:=n div 10;
  end;
  if (k=4)or(k=7)
    then writeln('YES')
    else writeln('NO');
end.