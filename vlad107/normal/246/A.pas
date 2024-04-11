var
  n,i:longint;

begin
  read(n);
  if (n<3)then begin
    writeln('-1');
    exit;
  end;
  for i:=n downto 1 do write(i,' ');
  writeln;
end.