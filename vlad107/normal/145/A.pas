var                                      
  x,y,i:longint;
  a,b:ansistring;

begin
  readln(a);
  readln(b);

  x:=0;y:=0;
  for i:=1 to length(a)do
    if (a[i]='7')and(b[i]='4')then inc(x)else
    if (a[i]='4')and(b[i]='7')then inc(y);
  if (x>y)then writeln(x)else writeln(y);
end.