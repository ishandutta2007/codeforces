const
  inf:int64=2000000000000000;

var
  d,f:array[0..333,0..333]of int64;
  x,y,z,t,nj,n,m,k,i,j:longint;
  cr:int64;

begin
  read(n,m,k);
  for i:=1 to n do 
    for j:=i to n do d[i][j]:=inf;
  for i:=1 to m do begin
    read(x,y,z);
    if (z<d[x][y])then d[x][y]:=z;
  end;
  for i:=1 to n do 
    for j:=n downto i do begin
      if (i<j)and(d[i][j]<d[i+1][j])then d[i+1][j]:=d[i][j];
      if (i<j)and(d[i][j]<d[i][j-1])then d[i][j-1]:=d[i][j];
    end;
  {for t:=1 to n do 
    for i:=1 to t do 
      for j:=t to n do 
        if (d[i][t]+d[t][j]<d[i][j])then d[i][j]:=d[i][t]+d[t][j];}
  f[0][0]:=0;
  for i:=1 to k do f[0][i]:=inf;
  for i:=1 to n do 
    for j:=0 to k do begin
      f[i][j]:=f[i-1][j];
      for t:=0 to i-1 do begin
        nj:=j-(i-t);
        if (nj<0)then nj:=0;
        cr:=f[t][nj]+d[t+1][i];
        if (cr<f[i][j])then f[i][j]:=cr;
      end;
    end;
  if (f[n][k]=inf)then f[n][k]:=-1;
  writeln(f[n][k]);
end.