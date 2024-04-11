var
  n,x:longint;
begin
  read(n);
  x:=1;
  while (5*x<n)do begin
    dec(n,5*x);
    x:=x*2;
  end;
  n:=(n-1)div x;
  if (n=0)then writeln('Sheldon')else
  if (n=1)then writeln('Leonard')else
  if (n=2)then writeln('Penny')else
  if (n=3)then writeln('Rajesh')else
  if (n=4)then writeln('Howard');
end.