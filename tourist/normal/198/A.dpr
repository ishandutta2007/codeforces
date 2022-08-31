{$R-,S-,Q-,I-,O+}
var
  k,b,n,t,x: int64;
begin
  read(k,b,n,t);
  x:=1;
  while k*x+b <= t do
  begin
    x:=k*x+b;
    dec(n);
  end;
  if n < 0 then n:=0;
  writeln(n);
end.