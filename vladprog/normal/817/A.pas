var
  x1,y1,x2,y2,x,y:longint;

begin
  read(x1,y1,x2,y2,x,y);
  if (((x1-x2) mod x)=0)and(((y1-y2) mod y)=0)and
     (not odd((x1-x2) div x + (y1-y2) div y))
    then writeln('YES')
    else writeln('NO')
end.