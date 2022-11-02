var
  tmp,r,c,n,m,i,j,x,y,cr,res:longint;
  a:array[1..1000,1..1000] of longint;

begin
  read(n,m);
  for i:=1 to n do for j:=1 to m do read(a[i][j]);
  res:=100000000;
  read(r,c);
  for i:=1 to n do for j:=1 to m do begin
    if (i+r-1<=n)and(j+c-1<=m)then begin
      cr:=0;
      for x:=0 to r-1 do for y:=0 to c-1 do 
        inc(cr,a[x+i][y+j]);
      if (cr<res)then res:=cr;
    end;
    tmp:=r;r:=c;c:=tmp;
    if (i+r-1<=n)and(j+c-1<=m)then begin
      cr:=0;
      for x:=0 to r-1 do for y:=0 to c-1 do 
        inc(cr,a[x+i][y+j]);
      if (cr<res)then res:=cr;
    end;
    tmp:=r;r:=c;c:=tmp;
  end;
  writeln(res);
end.