var n,i,j,now,x,ans:longint;
    t:array[0..100007] of longint;
begin
  readln(n);
  fillchar(t,sizeof(t),0);
  now:=0;
  ans:=0;
  for i:=1 to n*2 do
  begin
    read(x);
    if (t[x]=0) then
    begin
	  t[x]:=1;
	  inc(now);
	end else
	begin
	  t[x]:=0;
	  dec(now);
	end;
	if (now>ans) then ans:=now;
  end;
	readln;
  writeln(ans);
end.