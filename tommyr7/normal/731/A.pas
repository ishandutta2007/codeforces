var s:string;
    ans,i,now,x:longint;
begin
  now:=97;
  readln(s);
  ans:=0;
  for i:=1 to length(s) do
  begin
    x:=abs(ord(s[i])-now);
    if (26-x<x) then x:=26-x;
	ans:=ans+x;
    now:=ord(s[i]);
  end;
  writeln(ans);
end.