var
  n,i,j:longint;

begin
  read(n);
  for i:=0 to n do begin
    for j:=1 to (n-i)*2 do write(' ');
    write('0');
    for j:=1 to i do write(' ',j);
    for j:=i-1 downto 0 do write(' ',j);
    writeln;
  end;
  for i:=n-1 downto 0 do begin
    for j:=1 to (n-i)*2 do write(' ');
    write('0');
    for j:=1 to i do write(' ',j);
    for j:=i-1 downto 0 do write(' ',j);
    writeln;
  end;
end.