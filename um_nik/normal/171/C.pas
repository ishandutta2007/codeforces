var x,n,i,ans:integer;
begin
read(n);
ans:=0;
for i:=1 to n do
  begin
  read(x);
  ans+=i*x;
  end;
writeln(ans);
end.