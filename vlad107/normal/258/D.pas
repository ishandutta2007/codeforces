var
  res:extended;
  f:array[0..1111,0..1111]of extended;
  tt,i,j,n,m,x,y:longint;
  g:array[0..11111]of extended;
  a:array[0..500500]of longint;

begin
  read(n,m);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do 
    for j:=1 to n do 
      if (a[i]>a[j])then f[i][j]:=1 else f[i][j]:=0;
  for tt:=1 to m do begin
    read(x,y);
    for i:=1 to n do g[i]:=0.5*f[i][x]+0.5*f[i][y];
    for i:=1 to n do begin
      if (i=x)or(i=y)then continue;
      f[i][x]:=g[i];f[i][y]:=g[i];
      f[x][i]:=1-g[i];f[y][i]:=1-g[i];
    end;
    f[x][y]:=0.5;
    f[y][x]:=0.5;
  end;
  res:=0;
  for i:=1 to n do for j:=i+1 to n do res:=res+f[i][j];
  writeln(res:0:10);
end.