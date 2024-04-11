var
  n,m,k,i,j,x,y:longint;
  res:int64;
  a:array[0..555,0..555]of char;
  g,u:array[0..555,0..555]of longint;

  function sum(x1,y1,x2,y2:longint):longint;
    begin
      sum:=g[x2][y2]-g[x1-1][y2]-g[x2][y1-1]+g[x1-1][y1-1];
    end;

begin
  readln(n,m,k);
  for i:=1 to n do begin
    for j:=1 to m do read(a[i][j]);
    readln;
  end;
  fillchar(g,sizeof(g),$0);
  for i:=3 to n do
    for j:=3 to m do
      if (a[i][j-1]='1')and(a[i-1][j]='1')and(a[i-1][j-1]='1')and(a[i-1][j-2]='1')and(a[i-2][j-1]='1')
        then u[i][j]:=1;
  for i:=1 to n do for j:=1 to m do g[i][j]:=g[i-1][j]+g[i][j-1]-g[i-1][j-1]+u[i][j];
  res:=0;

  for i:=3 to n do
    for j:=3 to m do begin
      y:=j;
      while (y>3)and(sum(i,y,i,j)<k)do dec(y);

      for x:=i downto 3 do begin
        while (y<j)and(sum(x,y+1,i,j)>=k)do inc(y);
        if (sum(x,y,i,j)>=k)then inc(res,y-2);
      end;
    end;
  writeln(res);
end.