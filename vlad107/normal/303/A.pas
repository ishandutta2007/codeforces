var
  i,n:longint;

begin
  read(n);
  if (n mod 2=0)then begin
    writeln(-1);
    exit;
  end;
  for i:=1 to n do write(i-1,' ');
  writeln;
  for i:=1 to n do write(i-1,' ');
  writeln;
  for i:=0 to n-1 do write((2*i)mod n,' ');
  writeln;
end.