var i,j,a,b1,b,anss:longint;
    ans:array[1..100] of longint;
begin
  readln(a,b1);
  b:=b1;
  anss:=0;
  fillchar(ans,sizeof(ans),0);
  while (b>a) do
  begin
    if (b mod 10=1) then
    begin
	  b:=b div 10;
	  inc(anss);
	  ans[anss]:=b;
	end
	else if (b mod 2=0) then
	begin
	  b:=b div 2;
	  inc(anss);
	  ans[anss]:=b;
	end
	else
	begin
	  writeln('NO');
	  halt;
	end;
  end;
  if (b=a) then
  begin
    writeln('YES');
    writeln(anss+1);
    for i:=anss downto 1 do
		write(ans[i],' ');
	writeln(b1);
  end else writeln('NO');
end.