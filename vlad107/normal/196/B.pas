const
  hx:array[1..4]of longint=(0,1,0,-1);
  hy:array[1..4]of longint=(1,0,-1,0);
  mbase=10000007;

var
  ux,uy,kh,cx,cy,n,m,sx,sy,i,j,xx,yy,qb,qe:longint;
  a:array[0..1555,0..1555]of char;
  vx,vy:array[0..1555,0..1555]of longint;
  used:array[0..1555,0..1555]of boolean;
  qx,qy:array[0..1555*1555]of longint;
    
begin
  readln(n,m);
  sx:=0;sy:=0;
  for i:=1 to n do begin
    for j:=1 to m do begin
      read(a[i][j]);
      if (a[i][j]='S')then begin
        sx:=i;sy:=j;
      end;
    end;
    readln;
  end;
  qb:=0;qe:=1;
  qx[1]:=sx;qy[1]:=sy;
  vx[sx][sy]:=sx;
  vy[sx][sy]:=sy;
  used[sx][sy]:=true;
  while (qb<qe)do begin
    inc(qb);
    xx:=qx[qb];yy:=qy[qb];
    for i:=1 to 4 do begin
      cx:=xx+hx[i];
      cy:=yy+hy[i];
      ux:=(cx+int64(n)*1000000-1)mod n+1;
      uy:=(cy+int64(m)*1000000-1)mod m+1;
      if (a[ux][uy]='#')then continue;
      if (used[ux][uy])then begin
        if (vx[ux][uy]<>cx)or(vy[ux][uy]<>cy)then begin
          writeln('Yes');
          exit;
        end;
        continue;
      end;
      used[ux][uy]:=true;
      vx[ux][uy]:=cx;
      vy[ux][uy]:=cy;
      inc(qe);
      qx[qe]:=cx;
      qy[qe]:=cy;
    end;
  end;
  writeln('No');
end.