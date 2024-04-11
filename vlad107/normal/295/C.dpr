const
  m=1000000007;

var
  f,d:array[0..1,0..55,0..55]of longint;
  c:array[0..55,0..55]of longint;
  h,p,l:array[0..500500]of longint;
  u,a,b,t,s,n,k,i,j,x,y:longint;
  
  procedure dfs(u,x,y:longint);
    var
      i,j:longint;
    begin
      if (f[u][x][y]<>-1)then exit;
      f[u][x][y]:=0;
      for i:=0 to x do 
        for j:=0 to y do
          if (i+j>0)and(50*i+100*j<=k)and(d[1-u][a-x+i][b-y+j]+1=d[u][x][y])then begin
            dfs(1-u,a-x+i,b-y+j);
            inc(f[u][x][y],int64(c[b-y+j][j])*(int64(f[1-u][a-x+i][b-y+j])*c[a-x+i][i] mod m)mod m);
            if (f[u][x][y]>=m)then dec(f[u][x][y],m);
          end;
    end;

begin
  for i:=0 to 50 do for j:=0 to 50 do 
    if (j=i)or(j=0)then c[i][j]:=1 else c[i][j]:=(c[i-1][j]+c[i-1][j-1])mod m;
  read(n,k);
  for i:=1 to n do begin
    read(t);
    if (t=50)then inc(a)else inc(b);
  end;
  for i:=0 to 1 do for x:=0 to a do for y:=0 to b do begin
    d[i][x][y]:=m;f[i][x][y]:=-1;
  end;
  t:=1;h[1]:=0;p[1]:=a;l[1]:=b;
  d[0][a][b]:=0;f[0][a][b]:=1;
  while (s<t)do begin
    inc(s);u:=h[s];x:=p[s];y:=l[s];
    for i:=0 to x do 
      for j:=0 to y do 
        if (i+j>0)and(50*i+100*j<=k)and(d[u][x][y]+1<d[1-u][a-x+i][b-y+j])then begin
          d[1-u][a-x+i][b-y+j]:=d[u][x][y]+1;
          inc(t);h[t]:=1-u;p[t]:=a-x+i;l[t]:=b-y+j;
        end;
  end;
  if (d[1][a][b]=m)then begin writeln(-1);writeln(0);exit;end;
  dfs(1,a,b);
  writeln(d[1][a][b]);
  writeln(f[1][a][b]);
end.