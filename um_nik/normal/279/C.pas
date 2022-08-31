var m,n,i,j,k,x,y:integer;
a,b,c:array [1..200000] of integer;
begin
readln(n,m);
for i:=1 to n do read(a[i]);
k:=1;
a[n+1]:=0;
for i:=1 to n do
  begin
  if k<i then k:=i;
  while (k<n) and (a[k]<=a[k+1]) do k+=1;
  b[i]:=k;
  end;
k:=1;
for i:=1 to n do
  begin
  if k<i then k:=i;
  while (k<n) and (a[k]>=a[k+1]) do k+=1;
  c[i]:=k;
  end;
{for i:=1 to n do write(b[i],' ');
writeln();
for i:=1 to n do write(c[i],' ');
writeln();}
for i:=1 to m do
  begin
  readln(x,y);
  k:=c[b[x]];
  if k<y then writeln('No') else writeln('Yes');
  end;
end.