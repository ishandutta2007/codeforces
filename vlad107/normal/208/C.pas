{$r-,q-,s-,i-,o+}
const
  inf=1000000000;

var
  n,m,i,j,x,y:longint;
  res,cr:extended;
  f:array[0..1,0..500500]of extended;
  dist:array[0..1,0..500500]of longint;
  d:array[0..555,0..555]of longint;
  used:array[0..500500]of boolean;
  
  procedure dej(sx,t:longint);
    var
      i,j,x,min:longint;
      
    begin
      for i:=1 to n do begin
        dist[t][i]:=inf;
        f[t][i]:=0;
      end;
      dist[t][sx]:=0;
      f[t][sx]:=1;
      for i:=1 to n do used[i]:=false;
      for i:=1 to n do begin
        min:=inf;
        x:=0;
        for j:=1 to n do 
          if (dist[t][j]<min)and(not used[j])then begin
            min:=dist[t][j];
            x:=j;
          end;
        if (x=0)then break;
        used[x]:=true;
        for j:=1 to n do 
          if (d[x][j]<>inf)then begin
            if (dist[t][x]+d[x][j]<dist[t][j])then begin
              dist[t][j]:=dist[t][x]+d[x][j];
              f[t][j]:=0;
            end;
            if (dist[t][x]+d[x][j]=dist[t][j])
              then f[t][j]:=f[t][j]+f[t][x];
          end;
      end;
    end;

begin
  read(n,m);
  for i:=1 to n do 
    for j:=1 to n do d[i][j]:=inf;
  for i:=1 to m do begin
    read(x,y);
    d[x][y]:=1;
    d[y][x]:=1;
  end;
  dej(1,0);
  dej(n,1);
  res:=0;
  for x:=1 to n do begin
    cr:=0;
    for i:=1 to n do 
      for j:=1 to n do 
        if (d[i][j]<>inf)and(dist[0][i]+dist[1][j]+1=dist[0][n])and((i=x)or(j=x))
          then cr:=cr+f[0][i]*f[1][j];
    if (cr/f[0][n]>res)then res:=cr/f[0][n];
  end;
  writeln(res:0:10);
end.