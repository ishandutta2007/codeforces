var n,i,j,ans,now:longint;
    anss:array[0..1000] of longint;
	ch:array[0..1000] of char;
begin
  readln(n);
  fillchar(anss,sizeof(anss),0);
  ans:=0;
  for i:=1 to n do
	read(ch[i]);
  readln;
  now:=0;
  for i:=1 to n do
  begin
    if (ch[i]='W') then
    begin
	  if (now>0) then
	  begin
	    inc(ans);
	    anss[ans]:=now;
	  end;
	  now:=0;
	end
	else inc(now);
  end;
  if (now>0) then 
  begin
    inc(ans);
    anss[ans]:=now;
  end;
  writeln(ans);
  for i:=1 to ans do
	write(anss[i],' ');
  writeln;
end.