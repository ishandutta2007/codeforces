var n,i,ans,tot:longint;
begin
  readln(n);
  tot:=0;
  ans:=0;
  while (tot<=n) do
  begin
    inc(ans);
    tot:=tot+ans;
  end;
  tot:=tot-ans;
  dec(ans);
  writeln(ans);
  for i:=1 to ans-1 do
	write(i,' ');
  writeln(n-tot+ans);
end.