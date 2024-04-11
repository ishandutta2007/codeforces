var n,m,i,x:integer;
begin
readln(m,n);
if n=3 then
  begin
  if m=3 then
    begin
    writeln('0 0');
    writeln('1 0');
    writeln('0 1');
    end;
  if m=4 then
    begin
    writeln('0 0');
    writeln('3 0');
    writeln('0 3');
    writeln('1 1');
    end;
  if m>4 then writeln(-1);
  end else
  begin
  x:=0;
  for i:=1 to n do
    begin
    x+=i;
    writeln(i,' ',x+10000000);
    end;
  x:=0;
  for i:=1 to m-n do
    begin
    x+=i;
    writeln(i,' ',-x-10000000);
    end;
  end;
end.