const
  INF=1000000000;
  hx:array[1..8]of longint=(1,0,-1,0,-1,-1,1,1);
  hy:array[1..8]of longint=(0,1,0,-1,1,-1,-1,1);
  ss:array[1..8]of string=('R','U','L','D','LU','LD','RD','RU');
var
  s:string;
  x,y,j,sx,sy,ex,ey,qb,qe,i,k,nx,ny,cx,cy:longint;
  d,pd:array[1..100,1..100]of longint;
  qx,qy,res:array[1..100000]of longint;
begin
  readln(s);
  sx:=ord(s[1])-96;
  sy:=ord(s[2])-48;
  readln(s);
  ex:=ord(s[1])-96;
  ey:=ord(s[2])-48;
  for i:=1 to 8 do
    for j:=1 to 8 do
      d[i][j]:=INF;
  d[sx][sy]:=0;
  qb:=0;qe:=1;
  qx[1]:=sx;
  qy[1]:=sy;
  while (qb<qe)do begin
    inc(qb);
    x:=qx[qb];
    y:=qy[qb];
    for i:=1 to 8 do begin
      cx:=x+hx[i];
      cy:=y+hy[i];
      if (cx<1)or(cy<1)or(cx>8)or(cy>8)then continue;
      if (d[x][y]+1>=d[cx][cy])then continue;
      d[cx][cy]:=d[x][y]+1;
      inc(qe);
      qx[qe]:=cx;
      qy[qe]:=cy;
      pd[cx][cy]:=i;
    end;
  end;
  writeln(d[ex][ey]);
  while (ex<>sx)or(ey<>sy)do begin
    i:=pd[ex][ey];
    inc(k);
    res[k]:=i;
    nx:=ex-hx[i];
    ny:=ey-hy[i];
    ex:=nx;ey:=ny;
  end;
  for i:=1 to k do writeln(ss[res[i]]);
end.