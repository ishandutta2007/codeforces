var n,i:integer;
begin
readln(n);
if n mod 2=1 then writeln(-1) else
begin
for i:=1 to n do
begin
if i mod 2=0 then write(i-1,' ') else write(i+1,' ');
end;
end;
end.