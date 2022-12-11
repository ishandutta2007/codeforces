var n,i,j,now,a:longint;
    tot:array[0..60000000] of longint;
	op,ch:char;
	x:int64;
begin
  readln(n);
  fillchar(tot,sizeof(tot),0);
  for i:=1 to n do
  begin
    read(op,ch);
    readln(x);
    now:=0;
    a:=1;
    while (x>0) do
	begin
	  if (x mod 2=1) then now:=now+a;
	  a:=a+a;
	  x:=x div 10;
	end;
	if (op='+') then inc(tot[now]);
	if (op='-') then dec(tot[now]);
	if (op='?') then writeln(tot[now]);
  end;
end.