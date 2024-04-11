{$r-,q-,s-,i-,o+}
var 
  g,f:array[0..888,0..4444]of longint;
  a:array[0..4444,0..4444]of longint;
  t,n,k,i,j,ss,ff:longint;
  
  function cost(x,y:longint):longint;inline;
    begin
      cost:=a[y][y]+a[x][x]-a[x][y]-a[y][x];
    end;

begin
  read(n,k);
  for i:=1 to n do 
    for j:=1 to n do begin
      read(a[i][j]);
      a[i][j]:=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+a[i][j];
    end;
  for i:=1 to k do
    for j:=n downto 1 do 
      if (i=1)then begin
        f[i][j]:=cost(0,j);
        g[i][j]:=0;
      end else begin
        if (j=n)then ff:=j-1 else ff:=g[i][j+1];
        ss:=g[i-1][j];
        f[i][j]:=maxlongint;
        for t:=ss to ff do 
          if (f[i-1][t]+cost(t,j)<f[i][j])then begin
            f[i][j]:=f[i-1][t]+cost(t,j);
            g[i][j]:=t;
          end;
      end;
  writeln(f[k][n] shr 1);
end.