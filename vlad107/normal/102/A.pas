var
  res,n,m,i,j,x,y,k:longint;
  a:array[0..500500]of longint;
  d:array[0..1111,0..1111]of boolean;

begin
  read(n,m);
  for i:=1 to n do read(a[i]);
  for i:=1 to m do begin
    read(x,y);
    d[x][y]:=true;
    d[y][x]:=true;
  end;
  res:=-1;
  for i:=1 to n do
    for j:=i+1 to n do
      for k:=j+1 to n do 
        if (d[i][j])and(d[j][k])and(d[i][k])and((res=-1)or(a[i]+a[j]+a[k]<res))
          then res:=a[i]+a[j]+a[k];
  writeln(res);
end.