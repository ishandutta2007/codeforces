var n,m,z,i,ans:longint;
begin
  readln(n,m,z);
  ans:=0;
  for i:=1 to z do
	if (i mod n=0) and (i mod m=0) then inc(ans);
  writeln(ans);
end.