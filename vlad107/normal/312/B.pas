var
  a,b,c,d,p1,p2:extended;

begin
  read(a,b,c,d);
  p1:=a/b;
  p2:=c/d;
  writeln(p1/(1-(1-p1)*(1-p2)):0:10);
end.