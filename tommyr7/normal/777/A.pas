var n,k,ans,now,i,j:longint;
begin
  readln(n);
  readln(k);
  n:=n mod 6;
  for i:=0 to 2 do
  begin
    now:=i;
    for j:=1 to n do
	begin
	  if (j mod 2=1) then
	  begin
	    if (now<2) then now:=1-now;
	  end else
	  begin
	    if (now>0) then now:=3-now;
	  end;
	end;
	if (now=k) then ans:=i;
  end;
  writeln(ans);
end.