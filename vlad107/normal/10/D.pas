{$r-,q-,s-,i-,o+}
var
  a,b,r:array[0..555]of longint;
  pd,f:array[0..555,0..555,1..2]of longint;
  n,m,i,j,k,x,y:longint;
begin
{  assign(input,'input.txt');reset(input);
  assign(output,'output.txt');rewrite(output);}
  read(n);
  for i:=1 to n do read(a[i]);
  read(m);
  for i:=1 to m do read(b[i]);
  for i:=1 to n do
    for j:=1 to m do
      for k:=1 to 2 do
        f[i][j][k]:=-1;
  a[0]:=-1;         
  b[0]:=-1;
  f[0][0][1]:=0;
  for i:=0 to n do
    for j:=0 to m do
      for k:=1 to 2 do begin
        if (f[i][j][k]=-1) then continue;
        if (k=1)then begin
          for x:=i+1 to n do
            if (a[x]>a[i])and(f[i][j][1]+1>f[x][j][2])then begin
              f[x][j][2]:=f[i][j][1]+1;
              pd[x][j][2]:=i;
            end;
        end else begin
          for x:=j+1 to m do
            if (b[x]=a[i])and(f[i][j][2]>f[i][x][1])then begin
              f[i][x][1]:=f[i][j][2];
              pd[i][x][1]:=j;
            end;
        end;
      end;
  x:=0;y:=0;
  for i:=1 to n do
    for j:=1 to m do
      if (f[i][j][1]>f[x][y][1])then begin
        x:=i;y:=j;
      end;
  writeln(f[x][y][1]);
  i:=1;
  k:=0;
  while (x>0)do begin
    if (i=1)then begin
      inc(k);
      r[k]:=a[x];
      y:=pd[x][y][i];
    end else x:=pd[x][y][i];
    i:=3-i;
  end;
  for i:=k downto 1 do write(r[i],' ');
end.