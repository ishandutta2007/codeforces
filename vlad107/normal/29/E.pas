{$r-,q-,s-,i-,o+}
type
  TPoint=record
    q,x,y:longint;
  end;
const
  INF=1000000000;
var
  px,py,cy,ii,qb,qe,kg,n,m,i,x,y,z:longint;
  d:array[0..555,0..555,0..2]of TPoint;
  qx,qy,qz,pred,last,g:array[0..5555555]of longint;
begin
  read(n,m);
  kg:=0;
  fillchar(last,sizeof(last),$0);
  fillchar(pred,sizeof(pred),$0);
  for i:=1 to m do begin
    read(x,y);
    inc(kg);g[kg]:=y;pred[kg]:=last[x];last[x]:=kg;
    inc(kg);g[kg]:=x;pred[kg]:=last[y];last[y]:=kg;
  end;
  for x:=1 to n do for y:=1 to n do for z:=0 to 1 do d[x][y][z].q:=INF;
  qb:=0;qe:=1;
  qx[1]:=1;qy[1]:=n;qz[1]:=0;
  d[1][n][0].q:=0;
  while (qb<qe)do begin
    inc(qb);x:=qx[qb];y:=qy[qb];z:=qz[qb];
    if (z=0)then begin
      ii:=last[x];
      while (ii>0)do begin
        cy:=g[ii];
        if (d[x][y][z].q+1<d[cy][y][1-z].q)then begin
          d[cy][y][1-z].q:=d[x][y][z].q+1;
          d[cy][y][1-z].x:=x;
          d[cy][y][1-z].y:=y;
          inc(qe);
          qx[qe]:=cy;qy[qe]:=y;qz[qe]:=1-z;
        end;
        ii:=pred[ii];
      end;
    end else begin
      ii:=last[y];
      while (ii>0)do begin
        cy:=g[ii];
        if (cy<>x)and(d[x][y][z].q+1<d[x][cy][1-z].q)then begin
          d[x][cy][1-z].q:=d[x][y][z].q+1;
          d[x][cy][1-z].x:=x;
          d[x][cy][1-z].y:=y;
          inc(qe);
          qx[qe]:=x;qy[qe]:=cy;qz[qe]:=1-z;
        end;
        ii:=pred[ii];
      end;
    end;
  end;
  if (d[n][1][0].q=INF)then begin
    writeln(-1);
    exit;
  end;
  writeln(d[n][1][0].q div 2);
  x:=n;y:=1;z:=0;
  while (x<>1)or(y<>n)or(z<>0)do begin
    if (z=0)then write(y,' ');
    px:=d[x][y][z].x;
    py:=d[x][y][z].y;
    z:=1-z;x:=px;y:=py;
  end;
  writeln(y);
  x:=n;y:=1;z:=0;
  while (x<>1)or(y<>n)or(z<>0)do begin
    if (z=0)then write(x,' ');
    px:=d[x][y][z].x;
    py:=d[x][y][z].y;
    z:=1-z;x:=px;y:=py;
  end;
  writeln(x);
end.