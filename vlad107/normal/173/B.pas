{
	1 right
	2 down
	3 up 
	4 left}
const
  inf=1000000000;
  hx:array[1..4]of longint=(0,1,-1,0);
  hy:array[1..4]of longint=(1,0,0,-1);

var
  d:array[0..1111,0..1111,1..4]of longint;
  a:array[0..1111,0..1111]of char;
  cr,i,j,n,m,x,y,z,cx,cy,cz,qb,qe:longint;
  qx,qy,qz:array[0..10000000]of word;

begin
  readln(n,m);
  for i:=1 to n do begin
    for j:=1 to m do read(a[i][j]);
    readln;
  end;
  for i:=1 to n do 
    for j:=1 to m do 
      for x:=1 to 4 do d[i][j][x]:=inf;
  d[1][1][1]:=0;
  qb:=0;qe:=1;
  qx[1]:=1;qy[1]:=1;qz[1]:=1;
  while (qb<qe)do begin
	inc(qb);
	x:=qx[qb];y:=qy[qb];z:=qz[qb];
	for cz:=1 to 4 do begin
	  if (cz<>z)and(a[x][y]='.')then continue;
	  cr:=d[x][y][z]+ord(cz<>z);
	  cx:=x+hx[cz];
	  cy:=y+hy[cz];
	  if (cx<1)or(cy<1)or(cx>n)or(cy>m)then continue;
	  if (cr>=d[cx][cy][cz])then continue;
	  d[cx][cy][cz]:=cr;
	  inc(qe);
	  qx[qe]:=cx;qy[qe]:=cy;qz[qe]:=cz;
	end;
  end;
  for i:=2 to 4 do 
    if (a[n][m]='#')and(d[n][m][i]+1<d[n][m][1])then d[n][m][1]:=d[n][m][i]+1;
  if (d[n][m][1]=inf)then d[n][m][1]:=-1;
  writeln(d[n][m][1]);
end.