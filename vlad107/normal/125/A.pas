var
  x,n,i:longint;

begin
  read(n);
  i:=0;
  while (36*(i+1)<=n)do inc(i);
  if (n mod 36=35)then begin
    writeln(i+1,' 0');exit;
  end;
  write(i,' ');
  n:=n-36*i;
  x:=n div 3;
  if (n mod 3>1)then inc(x);
  writeln(x);
end.