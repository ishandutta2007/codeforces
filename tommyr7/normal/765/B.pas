var vis:array[0..30] of boolean;
    last:array[0..30] of longint;
    ch:char;
	i,j:longint;
	ans:boolean;
begin
  fillchar(vis,sizeof(vis),false);
  fillchar(last,sizeof(last),0);
  i:=0;
  while not(eoln) do
  begin
    inc(i);
    read(ch);
    if (last[ord(ch)-96]=0) then last[ord(ch)-96]:=i;
    vis[ord(ch)-96]:=true;
  end;
  readln;
  i:=1;
  while (i<=26) and vis[i] do inc(i);
  ans:=true;
  for j:=i to 26 do
	if vis[j] then ans:=false;
  for j:=1 to i-2 do
	if (last[j]>last[j+1]) then ans:=false;
  if ans then writeln('YES') else writeln('NO');
end.