const 
  inf=1000000000;
var
  res,n,m,i,j:longint;
  f:array[1..111,0..111]of longint;
  a:array[1..111]of longint;
begin
  read(n,m);
  for i:=1 to n do begin
    read(a[i]);
    a[i]:=-a[i];
  end;
  for i:=1 to n+1 do 
    for j:=0 to m do 
      f[i][j]:=-inf;
  f[1][0]:=0;
  for i:=1 to n do  
    for j:=0 to m do begin
      if (f[i][j]=-inf)then continue;
      if (j<m)and(f[i][j]+a[i]>f[i+1][j+1])then f[i+1][j+1]:=f[i][j]+a[i];
      if (f[i][j]>f[i+1][j])then f[i+1][j]:=f[i][j];
    end;
  res:=0;
  for j:=0 to m do 
    if (f[n+1][j]>res)then res:=f[n+1][j];
  writeln(res);
end.