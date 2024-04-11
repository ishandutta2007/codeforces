uses
  math;
const
  base=1000000007;
var
  q,res,n,i,j,m:longint;
  sx,x,y:array[0..1111]of longint;
  c,f:array[0..1111,0..1111]of longint;
begin
  read(n);
  y[0]:=0;
  for i:=1 to n do begin
    read(x[i]);
    y[i]:=y[i-1]+x[i];
  end;
  m:=y[n];
  for i:=0 to m do
    for j:=0 to m do
      if (i=j)or(j=0)then c[i][j]:=1 else
      if (j>i)then c[i][j]:=0 else
      c[i][j]:=(c[i-1][j]+c[i-1][j-1])mod base;
  for i:=1 to n do begin
    read(j);
    if (j<y[i])then y[i]:=j;
  end;
  fillchar(f,sizeof(f),$0);
  sx[0]:=0;
  for i:=1 to n do
    sx[i]:=sx[i-1]+x[i];
  x[n+1]:=0;
  f[1][x[1]]:=c[m][x[1]];
  for i:=1 to n do
    for j:=0 to m do
      if (f[i][j]>0)then
        for q:=0 to min(y[i],j)do
          f[i+1][j-q+x[i+1]]:=((int64(f[i][j])*c[j][q] mod int64(base))*c[m-sx[i]][x[i+1]]+f[i+1][j-q+x[i+1]])mod int64(base);
  writeln(f[n+1][0]);
end.