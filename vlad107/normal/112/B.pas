var
  n,x,y:longint;

begin
  read(n,x,y);  
  if (n=2)then writeln('NO')else 
  if (x>=n div 2)and(y>=n div 2)and(x<=n div 2+1)and(y<=n div 2+1)then writeln('NO')else writeln('YES');
end.