uses
  math;

var
  n,k,l,c,d,p,nl,np:longint;

begin
  read(n,k,l,c,d,p,nl,np);
  k:=k*l;
  c:=c*d;
  nl:=nl*n;
  np:=np*n;
  writeln(min(min(k div nl,p div np),c div n));
end.