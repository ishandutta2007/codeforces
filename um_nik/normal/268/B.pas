var i:integer;
n,a:int64;
begin
readln(n);
a:=0;
for i:=1 to n-1 do
  begin
  a:=a+i*(n-i);
  end;
a+=n;
writeln(a);
end.