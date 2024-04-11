{$r-,q-,s-,i-,o+}
const
  inf=1000000000;
  hx:array[1..4]of longint=(0,1,-1,0);
  hy:array[1..4]of longint=(1,0,0,-1);
var
  res,max,cr,n,m,i,j,qb,qe,t,x,y,cx,cy:longint;
  fbl:boolean;
  a:array[0..111,0..111]of char;
  d:array[0..111,0..111]of longint;
  qx,qy:array[0..111111]of longint;

begin
  readln(n,m);
  fbl:=false;
  for i:=1 to n do begin
    for j:=1 to m do begin
      read(a[i][j]);
      if (a[i][j]='B')then fbl:=true;
    end;
    readln;
  end;
  if (not fbl)then begin
    writeln(0);
    exit;
  end;
  res:=inf;
  for i:=1 to n do
    for j:=1 to m do begin
      for x:=1 to n do for y:=1 to m do d[x][y]:=inf;
      d[i][j]:=0;
      qb:=0;qe:=1;
      qx[1]:=i;qy[1]:=j;
      while (qb<qe)do begin
        inc(qb);
        x:=qx[qb];y:=qy[qb];
        for t:=1 to 4 do begin
          cx:=x+hx[t];
          cy:=y+hy[t];
          if (cx<1)or(cy<1)or(cx>n)or(cy>m)then continue;
          cr:=ord(a[x][y]<>a[cx][cy]);
          if (d[x][y]+cr<d[cx][cy])then begin
            d[cx][cy]:=d[x][y]+cr;
            inc(qe);
            qx[qe]:=cx;
            qy[qe]:=cy;
          end;
        end;
      end;
      max:=0;
      for x:=1 to n do
        for y:=1 to m do
          if (a[x][y]='B')and(d[x][y]>max)then max:=d[x][y];
      if (max<res)then res:=max;
    end;
  writeln(res+1);
end.