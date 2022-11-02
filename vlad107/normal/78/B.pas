var
  n:longint;
begin
  read(n);
  while (n>=10)do begin
    write('ROYGB');
    dec(n,5);
  end;
  if (n mod 5=2)then writeln('ROYGBIV')else
  if (n mod 5=3)then writeln('ROYGBIVG')else 
  if (n mod 5=4)then writeln('ROYGBRIVG')else
  if (n mod 5=0)then writeln('ROYIV')else
  if (n mod 5=1)then writeln('ROYGIV');
end.