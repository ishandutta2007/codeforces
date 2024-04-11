uses math;

var
  n,k,a,s,i:longint;

begin
  read(n,k);
  s:=0;
  for i:=1 to n do
    begin
      read(a);
      inc(s,a)
    end;
  writeln(max(n*(2*k-1)-2*s,0))
end.