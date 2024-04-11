var n,m,i,p:integer;
begin
readln(n,m);
p:=n;
if p>m then p:=m;
writeln(p+1);
for i:=0 to p do
  begin
  writeln(p-i,' ',i);
  end;
end.