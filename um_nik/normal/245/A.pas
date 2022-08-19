var n,i,x,a,b,c,d:integer;
begin
readln(n);
a:=0;
b:=0;
c:=0;
d:=0;
for i:=1 to n do
  begin
  read(x);
  if x=1 then
    begin
    c:=c+5;
    read(x);
    a:=a+x;
    readln(x);
    end else
    begin
    d:=d+5;
    read(x);
    b:=b+x;
    readln(x);
    end;
  end;
if a>=c then writeln('LIVE') else writeln('DEAD');
if b>=d then writeln('LIVE') else writeln('DEAD');
end.