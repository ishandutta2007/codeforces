var x:char;
    flag:array[1..26] of boolean;
	ch:array[1..60000] of char;
	i,j,k,ans,now,n:longint;
begin
  n:=0;
  while not(eoln) do
  begin
    inc(n);
    read(ch[n]);
  end;
  readln;
  for i:=1 to n-25 do
  begin
    fillchar(flag,sizeof(flag),false);
    ans:=0;
    now:=0;
    for j:=1 to 26 do
		if (ch[i+j-1]<>'?') then flag[ord(ch[i+j-1])-64]:=true else inc(ans);
	for j:=1 to 26 do
		if not(flag[j]) then inc(now);
	if (ans>=now) then
	begin
	  now:=1;
	  for k:=1 to i-1 do
		if (ch[k]<>'?') then write(ch[k]) else write('A');
	  for k:=i to i+25 do
		if (ch[k]<>'?') then write(ch[k]) else
		begin
		  while (now<=25) and flag[now] do inc(now);
		  flag[now]:=true;
		  write(chr(now+64));
		end;
	  for k:=i+26 to n do
		if (ch[k]<>'?') then write(ch[k]) else write('Z');
	  writeln;
	  halt;
	end;
  end;
  writeln('-1');
end.