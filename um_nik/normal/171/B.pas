var n,i,ans:integer;
begin
readln(n);
ans:=1;
for i:=2 to n do
  begin
  ans+=12*(i-1);
  end;
writeln(ans);
end.