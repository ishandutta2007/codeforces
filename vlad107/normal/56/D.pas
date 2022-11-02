var
  sq,s,p:ansistring;
  a:array[1..1111]of ansistring;
  n,m,i,j,kn,pi,pj:longint;
  f:array[0..1111,0..1111]of longint;
  function min(x,y:longint):longint;
    begin
      if (x<y)then min:=x else min:=y;
    end;
begin
  readln(s);
  n:=length(s);
  readln(p);
  m:=length(p);
  for i:=0 to n+1 do
    for j:=0 to m+1 do
      f[i][j]:=2222211;
  f[1][1]:=0;
  for i:=1 to n+1 do
    for j:=1 to m+1 do begin
      if (f[i][j]=2222211)then continue;
      if (i<=n)and(j<=m)and(s[i]=p[j])then f[i+1][j+1]:=min(f[i+1][j+1],f[i][j]);
      if (j<=m)then f[i][j+1]:=min(f[i][j]+1,f[i][j+1]);
      if (i<=n)then f[i+1][j]:=min(f[i][j]+1,f[i+1][j]);
      if (i<=n)and(j<=m)then f[i+1][j+1]:=min(f[i][j]+1,f[i+1][j+1]);
    end;
  i:=n+1;j:=m+1;
  writeln(f[n+1][m+1]);
  kn:=f[n+1][m+1];
  n:=f[n+1][m+1];
  while (i>1)or(j>1)do begin
    pi:=i-1;pj:=j-1;
    if (f[i-1][j]<f[pi][pj])then begin
      pi:=i-1;pj:=j;
    end;
    if (f[i][j-1]<f[pi][pj])then begin
      pi:=i;pj:=j-1;
    end;
    str(pi,sq);
    if (s[pi]<>p[pj])and(pi=i-1)and(pj=j-1)then begin
      str(pj,sq);
      a[n]:='REPLACE '+sq+' '+p[pj];
      dec(n);
    end else
    if (pi=i-1)and(pj=j)then begin
      str(pj,sq);
      a[n]:='DELETE '+sq;
      dec(n);
    end else
    if (pj=j-1)and(pi=i)then begin
      str(pj,sq);
      a[n]:='INSERT '+sq+' '+p[pj];
      dec(n);
    end;
    i:=pi;j:=pj;
  end;
  for i:=1 to kn do writeln(a[i]);
end.