var n,now:int64;
    k,i,tot,ans:longint;
begin
  readln(n,k);
if (n=0) then writeln(0) else
begin
  now:=n;tot:=0;
  while (now>0) do
  begin
    if (now mod 10=0) then inc(tot);
	now:=now div 10;
  end;
  if (tot<k) then
  begin
    now:=n;tot:=0;
    while (now>0) do
	begin
	  inc(tot);
	  now:=now div 10;
	end;
	writeln(tot-1);
  end else
  begin
	now:=n;tot:=0;ans:=0;
    while (now>0) and (tot<k) do
    begin
      if (now mod 10=0) then inc(tot) else inc(ans);
	  now:=now div 10;
    end;
	writeln(ans);
  end;
end;
end.