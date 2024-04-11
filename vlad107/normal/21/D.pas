{$r-,q-,s-,i-,o+}
const
  inf=1000000000;
var
  x,y,z,n,j,m,res,i,mask:longint;
  f:array[0..111,0..1 shl 15]of longint;
  used:array[0..111]of boolean;
  d:array[0..111,0..111]of longint;
  deg,ss,ff,tt,ww:array[0..111]of longint;
  procedure dfs(x:longint);
    var
      i:longint;
    begin
      if (used[x])then exit;
      used[x]:=true;
      for i:=1 to n do 
        if (d[x][i]<>inf)then dfs(i);
    end;
begin
  read(n,m);
  res:=0;
  for i:=1 to n do 
    for j:=1 to n do 
      d[i][j]:=inf;
  for i:=1 to m do begin
    read(x,y,z);
    inc(res,z);
    inc(deg[x]);
    inc(deg[y]);
    if (z<d[x][y])then begin
      d[x][y]:=z;
      d[y][x]:=z;
    end;
  end;
  fillchar(used,sizeof(used),false);
  dfs(1);
  for i:=1 to n do 
    if (not used[i])and(deg[i]>0)then begin
      writeln(-1);
      exit;
    end;
  m:=0;
  for i:=1 to n do 
    for j:=i+1 to n do 
      if (d[i][j]<inf)then begin
        inc(m);
	ss[m]:=i;ff[m]:=j;tt[m]:=d[i][j];
	ww[m]:=(1 shl (ss[m]-1))+(1 shl (ff[m]-1));
      end;
  for i:=1 to m+1 do  
    for mask:=0 to 1 shl n do f[i][mask]:=inf;
  mask:=0;
  for i:=1 to n do   
    if (deg[i] and 1>0)then inc(mask,1 shl (i-1));
  f[1][mask]:=0;
  for i:=1 to m do 
    for mask:=0 to 1 shl n-1 do begin
      if (f[i][mask]=inf)then continue;
      if (f[i][mask]<f[i+1][mask])then f[i+1][mask]:=f[i][mask];
      if (f[i+1][mask xor ww[i]]>f[i][mask]+tt[i])then f[i+1][mask xor ww[i]]:=f[i][mask]+tt[i];
    end;
  writeln(res+f[m+1][0]);
end.