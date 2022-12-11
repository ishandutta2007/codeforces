var n,k,i,now:longint;
begin
  readln(n,k);
  i:=1;
  while true do
  begin
    now:=i*n;
    if (now mod 10=0) or (now mod 10=k) then
    begin
	  writeln(i);
	  halt;
	end;
	inc(i);
  end;
end.