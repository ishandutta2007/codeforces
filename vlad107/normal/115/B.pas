var
  x,y,res,n,m,i,j,dir:longint;
  a:array[0..555,0..555]of char;

begin
  readln(n,m);
  for i:=1 to n do begin
    for j:=1 to m do read(a[i][j]);
    readln;
  end;
  while (n>0)do begin
    j:=1;
    while (j<=m)and(a[n][j]='G')do inc(j);
    if (j<=m)then break;
    dec(n);
  end;
  dir:=-1;
  y:=1;
  res:=0;
  for x:=1 to n do begin
    dir:=-dir;
    i:=y;
    if (dir=1)then begin
      for j:=y+1 to m do
        if (a[x][j]='W')or((x<n)and(a[x+1][j]='W'))then i:=j;
    end else begin
      for j:=y-1 downto 1 do
        if (a[x][j]='W')or((x<n)and(a[x+1][j]='W'))then i:=j;
    end;
    inc(res,abs(i-y));
    if (x<n)then inc(res);
    y:=i;
  end;
  writeln(res);
end.