var n,i:integer;
begin
readln(n);
if n<3 then writeln(-1) else
  begin
  write(3,' ',2);
  for i:=3 to n do write(' ',1);
  end;
end.