var
  n,t,k,d,t1:longint;

begin
  read(n,t,k,d);
  t1:=(n-1) div k * t;
  if d<t1
    then writeln('YES')
    else writeln('NO')
end.