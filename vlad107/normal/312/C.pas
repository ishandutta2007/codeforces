var
  i,n,k,t:longint;

begin
  read(n,k);
  t:=n*(n-1)div 2;
  if (t<=k)then writeln('no solution') else begin
    for i:=1 to n do writeln(0,' ',i);
  end;
end.