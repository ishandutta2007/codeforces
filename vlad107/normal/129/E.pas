const
  base=1000000007;
var
  g,f:array[0..1111,0..1111]of longint;
  n,m,k,nm,i,j,sum:longint;

begin
  read(n,m,k);
  nm:=n;
  if (m>nm)then nm:=m;
  fillchar(g,sizeof(g),$0);
  for j:=1 to nm do f[0][j]:=1;
  for j:=1 to nm do g[0][j]:=(g[0][j-1]+f[0][j])mod base;

  for i:=1 to k do begin
    sum:=0;
    for j:=3 to nm do begin
      sum:=(sum+g[i-1][j-2])mod base;
      f[i][j]:=sum;
      g[i][j]:=(g[i][j-1]+f[i][j])mod base;
    end;
  end;
  writeln(int64(f[k][n])*f[k][m] mod base);
end.