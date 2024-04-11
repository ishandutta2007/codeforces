const
  MAXN=2000;
  INF=10000000000000;

var
  res:int64;
  a:array[0..MAXN,0..MAXN] of longint;
  f:array[0..MAXN,0..MAXN] of int64;
  ss,ff,n,m,i,j:longint;

  function max(x,y:int64):int64;
    begin
      if (x>y)then max:=x else max:=y;
    end;

begin
  read(n,m);
  for i:=1 to n do for j:=1 to m do read(a[i][j]);
  f[1][1]:=a[1][1];
  for j:=2 to m do f[1][j]:=f[1][j-1]+a[1][j];
  for i:=2 to n do begin
    if (i and 1=0)then begin
      for j:=m-1 downto 1 do f[i-1][j]:=max(f[i-1][j],f[i-1][j+1]);
    end else begin
      for j:=2 to m do f[i-1][j]:=max(f[i-1][j],f[i-1][j-1]);
    end;
    f[i][1]:=a[i][1];
    for j:=2 to m do f[i][j]:=f[i][j-1]+a[i][j];
    if (i and 1=0)then begin
      for j:=2 to m do f[i][j]:=max(f[i][j],f[i][j-1]);
      for j:=1 to m-1 do f[i][j]:=f[i][j]+f[i-1][j+1];
      f[i][m]:=-INF;
    end else begin
      for j:=m-1 downto 1 do f[i][j]:=max(f[i][j],f[i][j+1]);
      for j:=2 to m do f[i][j]:=f[i][j]+f[i-1][j-1];
      f[i][1]:=-INF;
    end;
  end;
  res:=-INF;
  ss:=1;ff:=m;
  if (n and 1=1)then ss:=2 else ff:=m-1;
  for j:=ss to ff do
    if (f[n][j]>res)then res:=f[n][j];
  writeln(res);
end.