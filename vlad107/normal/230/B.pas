const
  maxn=1000000;

var
  prime:array[0..1111111]of boolean;
  t:int64;
  i,j,tt,x:longint;

begin
  fillchaR(prime,sizeof(prime),true);
  prime[1]:=false;
  for i:=2 to maxn do 
    if (prime[i])then 
      for j:=2 to maxn div i do prime[i*j]:=false;
  read(tt);
  while (tt>0)do begin
    dec(tt);
    read(t);
    x:=trunc(sqrt(t));
    if (int64(x)*x<>t)or(not prime[x])
      then writeln('NO')
      else writeln('YES');
  end;
end.