var i,m,n,x,amax,amin,bmin:integer;
begin
readln(n,m);
amax:=0;
amin:=10000;
for i:=1 to n do
  begin
  read(x);
  if x>amax then amax:=x;
  if x<amin then amin:=x;
  end;
if amax<2*amin then amax:=2*amin;
bmin:=100000;
for i:=1 to m do
  begin
  read(x);
  if x<bmin then bmin:=x;
  end;
if amax<bmin then writeln(amax) else writeln(-1);
end.