var
  k1,k0,x,sum,n,i:longint;

begin
  read(n);
  sum:=0;
  k1:=0;k0:=0;
  for i:=1 to n do begin
    read(x);inc(sum,x);
    if (x and 1=1)then inc(k1)else inc(k0);
  end;          
  if (sum and 1=1)then writeln(k1)else writeln(k0);
end.