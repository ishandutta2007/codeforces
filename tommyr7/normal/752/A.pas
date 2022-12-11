var n,m,x,k,a,b,c:longint;
begin
  readln(n,m,k);
  x:=(k+1) div 2;
  a:=x div m+1;
  b:=x mod m;
  if (b=0) then b:=m;
  if (b=m) then dec(a);
  write(a,' ',b,' ');
  if (k mod 2=1) then writeln('L') else writeln('R');
end.