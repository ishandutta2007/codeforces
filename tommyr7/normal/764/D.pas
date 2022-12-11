uses math;
var n,i,x,y,z,w:longint;
begin
  readln(n);
  writeln('YES');
  for i:=1 to n do
  begin
    readln(x,y,z,w);x:=abs(x);y:=abs(y);
    if (x mod 2=0) and (y mod 2=0) then writeln(1);
	if (x mod 2=0) and (y mod 2=1) then writeln(2);
	if (x mod 2=1) and (y mod 2=0) then writeln(3);
	if (x mod 2=1) and (y mod 2=1) then writeln(4);
  end;
end.