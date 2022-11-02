{$r-,q-,s-,i-,o+}
const
  inf=1000000000;

var
  i,j,ny,x,y,n,k,qb,qe:longint;
  f:array[0..5,0..500500]of longint;
  a:array[0..5,0..500500]of char;
  qx,qy:array[0..2000000]of longint;

begin
  readln(n,k);
  for i:=1 to 2 do begin
    for j:=1 to n do read(a[i][j]);
    readln;
  end;
  for i:=1 to 2 do
    for j:=1 to n+1 do f[i][j]:=inf;
  f[1][1]:=0;
  qb:=0;qe:=1;
  qx[1]:=1;qy[1]:=1;
  while (qb<=qe)do begin
    inc(qb);
    x:=qx[qb];
    y:=qy[qb];
    if (y-1>1)and(f[x][y]+1<f[x][y-1])then begin
      f[x][y-1]:=f[x][y]+1;
      if (f[x][y-1]<y-1)and(a[x][y-1]<>'X')then begin
        inc(qe);
        qx[qe]:=x;
        qy[qe]:=y-1;
      end;
    end;
    if (f[x][y]+1<f[x][y+1])then begin
      f[x][y+1]:=f[x][y]+1;
      if (y+1<>n+1)and(f[x][y+1]<y+1)and(a[x][y+1]<>'X')then begin
        inc(qe);
        qx[qe]:=x;
        qy[qe]:=y+1;
      end;
    end;
    ny:=y+k;
    if (ny>n+1)then ny:=n+1;
    if (f[x][y]+1<f[3-x][ny])then begin
      f[3-x][ny]:=f[x][y]+1;
      if (ny<>n+1)and(f[3-x][ny]<ny)and(a[3-x][ny]<>'X')then begin
        inc(qe);
        qx[qe]:=3-x;
        qy[qe]:=ny;
      end;
    end;
  end;
  if (f[1][n+1]<n+1)or(f[2][n+1]<n+1)
    then writeln('YES')
    else writeln('NO');
end.