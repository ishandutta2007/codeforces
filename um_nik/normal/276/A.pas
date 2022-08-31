var x,n,k,f,t,ans:int64;
i:integer;
begin
readln(n,k);
readln(f,t);
if t>k then x:=f-(t-k) else x:=f;
ans:=x;
for i:=2 to n do
  begin
  readln(f,t);
  if t>k then x:=f-(t-k) else x:=f;
  if x>ans then ans:=x;
  end;
writeln(ans);
end.