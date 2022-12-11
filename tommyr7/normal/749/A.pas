var n,i:longint;
begin
  readln(n);
  writeln(n div 2);
  for i:=1 to (n div 2)-1 do
	write(2,' ');
  if (n mod 2=0) then writeln(2) else writeln(3);
end.