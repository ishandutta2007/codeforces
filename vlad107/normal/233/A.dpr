var
  n,i:longint;

begin
  read(n);
  if (n and 1=1)then writeln(-1)else 
  for i:=1 to n do write(n-i+1,' ');
end.