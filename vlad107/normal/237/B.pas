var
  x,y,min,ux,uy,u,i1,i2,j1,j2,n,i,j,ca:longint;
  a:array[0..1111,0..1111]of longint;
  x1,y1,x2,y2,l:array[0..111111]of longint;
  
  procedure swap(sx,sy,ex,ey:longint);
    var
      tmp:longint;
    begin
      tmp:=a[sx][sy];a[sx][sy]:=a[ex][ey];a[ex][ey]:=tmp;
      inc(ca);
      x1[ca]:=sx;y1[ca]:=sy;x2[ca]:=ex;y2[ca]:=ey;
    end;

begin
  read(n);
  for i:=1 to n do read(l[i]);
  for i:=1 to n do
    for j:=1 to l[i] do read(a[i][j]);
  ca:=0;
  for i:=1 to n do 
    for j:=1 to l[i] do begin
      min:=1000000000;
      ux:=-1;uy:=-1;
      for x:=1 to n do
        for y:=1 to l[x] do
          if ((x>i)or(x=i)and(y>=j))and(a[x][y]<min)then begin
            min:=a[x][y];ux:=x;uy:=y;
          end;
      if (i<>ux)or(j<>uy)then swap(i,j,ux,uy);
    end;
  writeln(ca);
  for i:=1 to ca do writeln(x1[i],' ',y1[i],' ',x2[i],' ',y2[i]);
end.