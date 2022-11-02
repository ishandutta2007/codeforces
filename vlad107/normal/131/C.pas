{$r-,q-,s-,i-,o+}
var
  res:qword;
  c:array[0..50,0..50]of qword;
  nm,i,j,n,m,t:longint;

begin
  read(n,m,t);
  nm:=n;
  if (m>nm)then nm:=m;
  for i:=0 to nm do
    for j:=0 to i do
      if (j=0)then c[i][j]:=1 else
      c[i][j]:=c[i-1][j-1]+c[i-1][j];
  res:=0;
  for i:=4 to t-1 do
    if (i<=n)and(t-i<=m)
      then res:=res+c[n][i]*c[m][t-i];
  writeln(res);
end.