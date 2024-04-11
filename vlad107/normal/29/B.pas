{$r-,q-,s-,i-,o+}
var
  l,d,v,g,r:longint;
  t:extended;  
begin
  read(l,d,v,g,r);
  t:=d/v;
  while(t>=g+r)do t:=t-g-r;
  if (t<g)
    then t:=0
    else t:=g+r-t;
  t:=t+l/v;
  writeln(t:0:10);
end.