var n,k,now,ans,i:longint;
begin
  readln(n,k);
  k:=240-k;
  ans:=0;now:=0;
  for i:=1 to n do
  begin
    now:=now+5*i;
    if (now<=k) then ans:=i;
  end;
  writeln(ans);
end.