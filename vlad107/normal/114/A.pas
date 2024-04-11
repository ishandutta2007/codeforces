var
  a,b,k:longint;

begin
  read(a,b);
  k:=0;
  while (b mod a=0)do begin
    b:=b div a;
    inc(k);
  end;
  if (b=1)then begin
    writeln('YES');writeln(k-1);
  end else writeln('NO');
end.