var
  n,i:longint;

begin
  read(n);
  for i:=1 to n do 
    if (i mod 4=1)then write('a')else
    if (i mod 4=2)then write('b')else 
    if (i mod 4=3)then write('c')else
    write('d');
  writeln;
end.