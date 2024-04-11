var n,i:integer;
begin
readln(n);
if n mod 2=0 then writeln(-1) else
  begin
  for i:=0 to n-1 do write(i,' ');
  writeln();
  for i:=0 to n-1 do write(i,' ');
  writeln();
  for i:=0 to n-1 do write((2*i) mod n,' ');
  writeln();
  
  end;
end.