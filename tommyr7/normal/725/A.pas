var n,i,ans:longint;
    ch:array[0..200000] of char;
begin
  readln(n);
  for i:=1 to n do
	read(ch[i]);
  readln;
  ans:=0;
  for i:=1 to n do
	if (ch[i]='<') then inc(ans) else break;
  for i:=n downto 1 do
	if (ch[i]='>') then inc(ans) else break;
  writeln(ans);
end.