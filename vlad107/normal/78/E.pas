{$r-,q-,s-,i-,o+}
const
  inf=1000000000;
  hx:array[1..4]of longint=(1,0,0,-1);
  hy:array[1..4]of longint=(0,1,-1,0);
var
  cf,dz,d,f:array[0..555,0..555]of longint;
  a,b:array[0..555,0..555]of char;
  used:array[0..555,0..555]of boolean;
  res,pushed,ss,ff,y,x,nom,qb,qe,i,j,sx,sy,n,t,cx,cy:longint;
  ptr,level:array[0..555]of longint;
  qx,qy:array[0..500500]of longint;
  procedure dfs(x,y,tt:longint);
    var
      i:longint;
    begin
      if (used[x][y])then exit;
      if (dz[x][y]<tt)then exit;
      if (b[x][y]>='0')and(b[x][y]<='9')then begin
        i:=(x-1)*n+y+n*n;
        f[nom][i]:=inf;
      end;
      if (dz[x][y]=tt)then exit;
      used[x][y]:=true;
      for i:=1 to 4 do begin
        cx:=x+hx[i];
        cy:=y+hy[i];
        if (cx<1)or(cy<1)or(cx>n)or(cy>n)then continue;
        if (a[cx][cy]='Y')then continue;
        dfs(cx,cy,tt+1);
      end;
    end;
  function bfs:boolean;
    var
      i:longint;
    begin
      qb:=0;qe:=1;
      qx[1]:=0;
      fillchar(level,sizeof(level),$FF);
      level[0]:=0;
      while (qb<qe)do begin
        inc(qb);
        x:=qx[qb];
        for i:=1 to ff do
          if (cf[x][i]-f[x][i]>0)and(level[i]<0)then begin
            level[i]:=level[x]+1;
            inc(qe);
            qx[qe]:=i;
          end;
      end;
      bfs:=level[ff]>0;
    end;
  function calc(x,k:longint):longint;
    var
      pushed,i,cc:longint;
    begin
      if (k=0)then begin
        calc:=0;
        exit;
      end;
      if (x=ff)then begin
        calc:=k;
        exit;
      end;
      while (ptr[x]<=ff)do begin
        if (level[ptr[x]]<>level[x]+1)then begin
          inc(ptr[x]);
          continue;
        end;
        cc:=k;
        if (cf[x][ptr[x]]-f[x][ptr[x]]<cc)then cc:=cf[x][ptr[x]]-f[x][ptr[x]];
        pushed:=calc(ptr[x],cc);
        if (pushed<>0)then begin
          inc(f[x][ptr[x]],pushed);
          dec(f[ptr[x]][x],pushed);
          calc:=pushed;
          exit;
        end;
        inc(ptr[x]);
      end;
      calc:=0;
    end;
begin
  readln(n,t);
  for i:=1 to n do begin
    for j:=1 to n do begin
      read(a[i][j]);
      if (a[i][j]='Z')then begin
        sx:=i;sy:=j;
      end;
    end;
    readln;
  end;
  readln;
  for i:=1 to n do begin
    for j:=1 to n do read(b[i][j]);
    readln;
  end;
  for i:=1 to n do
    for j:=1 to n do d[i][j]:=inf;
  d[sx][sy]:=0;
  qb:=0;qe:=1;
  qx[1]:=sx;qy[1]:=sy;
  while (qb<qe)do begin
    inc(qb);
    x:=qx[qb];y:=qy[qb];
    for i:=1 to 4 do begin
      cx:=x+hx[i];
      cy:=y+hy[i];
      if (cx<1)or(cy<1)or(cx>n)or(cy>n)then continue;
      if (a[cx][cy]='Y')then continue;
      if (d[x][y]+1>=d[cx][cy])then continue;
      d[cx][cy]:=d[x][y]+1;
      inc(qe);
      qx[qe]:=cx;
      qy[qe]:=cy;
    end;
  end;
  for i:=1 to n do
    for j:=1 to n do dz[i][j]:=d[i][j];
  for i:=1 to n do
    for j:=1 to n do
      if (dz[i][j]>t)then dz[i][j]:=t;	
  fillchar(f,sizeof(f),$0);
  for i:=1 to n do
    for j:=1 to n do begin
      if (a[i][j]<'0')or(a[i][j]>'9')then continue;
      fillchar(used,sizeof(used),false);
      nom:=(i-1)*n+j;
      dfs(i,j,0);
    end;
  for i:=1 to n do
    for j:=1 to n do begin
      if (a[i][j]>='0')and(a[i][j]<='9')then begin
        x:=ord(a[i][j])-48;
        nom:=(i-1)*n+j;
        f[0][nom]:=x;
      end;
      if (b[i][j]>='0')and(b[i][j]<='9')then begin
        x:=ord(b[i][j])-48;
        nom:=(i-1)*n+j+n*n;
        f[nom][2*n*n+1]:=x;
      end;
    end;
  ss:=0;
  ff:=2*n*n+1;
  for i:=0 to ff do
    for j:=0 to ff do cf[i][j]:=f[i][j];
  fillchar(f,sizeof(f),$0);
  res:=0;
{  for i:=0 to ff do begin
    for j:=0 to ff do write(cf[i][j],' ');
    writeln;
  end;}
  while (true)do begin
    if (not bfs)then break;
    for i:=0 to ff do ptr[i]:=1;
    while (true)do begin
      pushed:=calc(0,inf);
      if (pushed=0)then break;
      inc(res,pushed);
    end;
  end;
  writeln(res);
end.