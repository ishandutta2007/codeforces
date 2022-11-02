{$r-,q-,s-,i-,o+}
var
  tt,mtk,t,n,m,i,j,k:longint;
  a:array[0..100]of longint;
  res,q:extended;
  c:array[0..111,0..111]of extended;
  f:array[0..111,0..111,0..111]of extended;
begin
  read(n,m);
  for i:=1 to m do read(a[i]);
  for i:=0 to m+1 do
    for j:=0 to n+1 do
      for k:=0 to n+1 do f[i][j][k]:=0;
  f[1][0][0]:=1;
  for i:=0 to n do
    for j:=0 to n do
      if (j=i)or(j=0)then c[i][j]:=1 else
      if (j>i)then c[i][j]:=0 else
      c[i][j]:=c[i-1][j]+c[i-1][j-1];
  for i:=1 to m do
    for j:=0 to n do
      for k:=0 to n do
        if (f[i][j][k]>0)then begin
          for t:=0 to n-j do begin
            mtk:=t div a[i];
            if (t mod a[i]>0)then inc(mtk);
            if (k>mtk)then mtk:=k;
            q:=c[n-j][t];
            for tt:=1 to t do q:=q/(m-i+1);
            for tt:=t+1 to n-j do q:=q*(m-i)/(m-i+1);
            f[i+1][j+t][mtk]:=f[i+1][j+t][mtk]+f[i][j][k]*q;
          end;
        end;
  res:=0;
  for i:=1 to n do
    res:=res+i*f[m+1][n][i];
  writeln(res:0:10);
end.