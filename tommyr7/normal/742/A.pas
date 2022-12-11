var n:longint;
begin
  readln(n);
  if (n=0) then writeln('1') else
  begin
    if (n mod 4=1) then writeln('8');
	if (n mod 4=2) then writeln('4');
	if (n mod 4=3) then writeln('2');
	if (n mod 4=0) then writeln('6');
  end;
end.