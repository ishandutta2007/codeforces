{$r-,q-,s-,i-,o+}
const
  inf=1000000000;
  MAXN=101;
  MAXA=100001;

var
  n,sx,sy,ex,ey,x,y,qb,qe,i,j:longint;
  qx,qy:array[0..MAXN*MAXA]of longint;
  a:array[0..MAXN]of longint;
  d:array[0..MAXN,0..MAXA]of longint;
  
  procedure up(x,y,c:longint);
    begin
      dec(x);
      if (x=0)then exit;
      if (y>a[x])then y:=a[x];
      if (c<d[x][y])then begin
        d[x][y]:=c;
        inc(qe);
        qx[qe]:=x;
        qy[qe]:=y;
      end;
    end;
    
  procedure down(x,y,c:longint);
    begin
      inc(x);
      if (x=n+1)then exit;
      if (y>a[x])then y:=a[x];
      if (c<d[x][y])then begin
        d[x][y]:=c;
        inc(qe);
        qx[qe]:=x;
        qy[qe]:=y;
      end;
    end;
    
  procedure left(x,y,c:longint);
    begin
      dec(y);
      if (y=0)then exit;
      if (c<d[x][y])then begin
        d[x][y]:=c;
        inc(qe);
        qx[qe]:=x;
        qy[qe]:=y;
      end;      
    end;
    
  procedure right(x,y,c:longint);
    begin
      inc(y);
      if (y=a[x]+1)then exit;
      if (c<d[x][y])then begin
        d[x][y]:=c;
        inc(qe);
        qx[qe]:=x;
        qy[qe]:=y;
      end;      
    end;

begin
  assign(input,'input.txt');reset(input);
  assign(output,'output.txt');rewrite(output);
  read(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do inc(a[i]);
  read(sx,sy,ex,ey);
  for i:=1 to n do for j:=1 to a[i] do d[i][j]:=inf;
  qb:=0;qe:=1;
  qx[1]:=sx;
  qy[1]:=sy;
  d[sx][sy]:=0;
  while (qb<qe)do begin
    inc(qb);
    x:=qx[qb];
    y:=qy[qb];
    up(x,y,d[x][y]+1);
    down(x,y,d[x][y]+1);
    left(x,y,d[x][y]+1);
    right(x,y,d[x][y]+1);
  end;
  writeln(d[ex][ey]);
  close(output);close(input);
end.