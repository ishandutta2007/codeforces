var n,k,now:int64;
begin
  readln(n,k);
  now:=1;
  while (k>0) do
  begin
    if (k mod 2=1) then break;
	k:=k div 2;
	inc(now);
  end;
  writeln(now);
end.