const
  hx:array[1..6]of longint=(1,-1,0,0,0,0);
  hy:array[1..6]of longint=(0,0,-1,1,0,0);
  hz:array[1..6]of longint=(0,0,0,0,-1,1);
var
  a:array[1..100,1..100,1..20]of char;
  res,x,y,z,n,m,k:longint;
  procedure dfs(x,y,z:longint);
    var
      i:longint;
    begin
      if (x<1)or(y<1)or(z<1)or(x>k)or(y>n)or(z>m)then exit;
      if (a[x][y][z]='#')then exit;
      inc(res);
      a[x][y][z]:='#';
      for i:=1 to 6 do dfs(x+hx[i],y+hy[i],z+hz[i]);
    end;
begin
  readln(k,n,m);
  for x:=1 to k do begin
    readln;
    for y:=1 to n do begin
      for z:=1 to m do read(a[x][y][z]);
      readln;
    end;
  end;
  read(x,y);
  res:=0;
  dfs(1,x,y);
  writeln(res);
end.