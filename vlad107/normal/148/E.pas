{$r-,q-,s-,i-,o+}
uses
  math;

var
  n,m,i,j,x,y,kg:longint;
  f:array[0..1111,0..1111]of longint;
  a,u,g:array[0..500500]of longint;

begin
  read(n,m);
  for i:=1 to m do g[i]:=-1;
  g[0]:=0;
  for i:=1 to n do begin
    read(kg);
    for j:=1 to kg do read(a[j]);
    for x:=1 to kg do 
      for y:=1 to kg do f[x][y]:=-1;
    f[1][kg]:=0;
    for x:=1 to kg do 
      for y:=kg downto 1 do 
        if (f[x][y]<>-1)then begin
          if (x<y)then f[x+1][y]:=max(f[x+1][y],f[x][y]+a[x]);
          if (x<y)then f[x][y-1]:=max(f[x][y-1],f[x][y]+a[y]);
        end;
    for j:=0 to kg do u[j]:=-1;
    for x:=1 to kg do 
      for y:=x to kg do begin
        j:=x-1+kg-y;
        u[j]:=max(u[j],f[x][y]);
        if (x=y)then u[j+1]:=max(u[j+1],f[x][y]+a[x]);
      end;
    for x:=m downto 0 do 
      if (g[x]<>-1)then 
        for j:=0 to kg do 
          g[x+j]:=max(g[x+j],g[x]+u[j]);
  end;
  writeln(g[m]);
end.