uses
  math;

var
  x1,x2,x3,x,m:longint;

begin
  read(x1,x2,x3);
  x:=(x1+x2+x3) div 3;
  m:=400;
  for x:=1 to 100 do
    m:=min(m,abs(x-x1)+abs(x-x2)+abs(x-x3));
  writeln(m)
end.