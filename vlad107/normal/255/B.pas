var
  s:ansistring;
  x,y,i:longint;

begin
  readln(s);
  for i:=1 to length(s)do
    if (s[i]='x')then inc(x)else inc(y);
  if (x-y>0)then for i:=1 to x-y do write('x')else
                  for i:=1 to y-x do write('y');
  writeln;
end.