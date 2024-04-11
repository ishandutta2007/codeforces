var
  n,i:longint;

begin
  read(n);
  for i:=1 to n do
    if i mod 4 < 2
      then write('a')
      else write('b');
  writeln
end.