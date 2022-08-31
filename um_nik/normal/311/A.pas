var n,k,i:integer;
begin
read(n,k);
if (n*(n-1)) div 2<=k then
  begin
  writeln('no solution');
  end else
  begin
  for i:=1 to n do writeln('0 ',i);
  end;
end.