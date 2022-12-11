var a,b,c,d,ans:longint;
begin
  readln(a,b);
  readln(c,d);
  for ans:=1 to 300000 do
	if (ans>=b) and ((ans-b) mod a=0) and (ans>=d) and ((ans-d) mod c=0) then break;
  if (ans<300000) then writeln(ans) else writeln(-1);
end.