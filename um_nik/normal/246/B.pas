var n,i,x,s:integer;
begin
readln(n);
s:=0;
for i:=1 to n do
  begin
  read(x);
  s:=s+x;
  end;
s:=abs(s);
if s mod n=0 then writeln(n) else writeln(n-1);
end.