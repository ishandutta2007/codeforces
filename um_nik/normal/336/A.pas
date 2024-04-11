var x,y,s:integer;
begin
readln(x,y);
s:=abs(x)+abs(y);
if x<0 then
  begin
  write(-s,' 0 0 ');
  if y>0 then writeln(s) else writeln(-s);
  end else
  begin
  if y>0 then writeln('0 ',s,' ',s,' 0') else writeln('0 ',-s,' ',s,' 0');
  end;
end.