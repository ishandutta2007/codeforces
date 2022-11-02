{$r-,q-,s-,i-,o+}
var
  res:int64;
  i,j,k,a,b,c,n,m,x,y:longint;
  f:array[0..777,0..777]of longint;
  g:array[0..777,0..777]of boolean;
  deg:array[0..777]of longint;

begin
  //assign(input,'input.txt');reset(input);
  read(n,m);
  for i:=1 to n do deg[i]:=0;
  for i:=1 to m do begin
    read(x,y);
    g[x][y]:=true;inc(deg[x]);
    g[y][x]:=true;inc(deg[y]);
  end;
  for i:=1 to n do dec(deg[i],2);
  for i:=1 to n do 
    for j:=i+1 to n do begin
      f[i][j]:=0;
      for k:=1 to n do inc(f[i][j],ord(g[i][k]and g[j][k]));
      f[j][i]:=f[i][j];
    end;
  res:=0;
  for a:=1 to n do 
    for b:=a+1 to n do 
      if (g[a][b])then 
        for c:=1 to n do
          if (c<>a)and(c<>b)then begin
            res:=res+(f[a][c]-ord(g[c][b]))*(f[b][c]-ord(g[c][a]));
            if (g[b][c])and(g[c][a])then res:=res-deg[c];
          end;
  writeln(res div 5);
end.