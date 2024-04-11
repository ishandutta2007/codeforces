{$r-,q-,s-,i-,o+}
{$M 100000000}
const
  inf=1000000000;
var
  d:array[0..1111,0..1111]of longint;
  qx,qy:array[0..1000000]of longint;
  mhx,mhy,ox,oy,hx,hy:array[0..1000000]of longint;
  ko,max,xx,yy,cx,cy,qb,qe,n,m,i,sx,sy,j,maxr,res:longint;
  procedure dfs(xx,yy:longint);
    var
      i,cx,cy:longint;
    begin
      d[xx][yy]:=1;
      for i:=1 to n do begin
        cx:=xx+mhx[i];
        cy:=yy+mhy[i];
        if (cx<0)or(cy<0)then continue;
        cx:=xx+hx[i];
        cy:=yy+hy[i];
        if (cx+cy>maxr)then continue;
        if (d[cx][cy]=2)then continue;
        if (d[cx][cy]=1)then begin
          writeln('Draw');
          halt(0);
        end;
        dfs(cx,cy);
      end;
      d[xx][yy]:=2;
    end;
  procedure dfs2(xx,yy:longint);
    var
      i,cx,cy:longint;
    begin
      d[xx][yy]:=1;
      if (xx+yy<=maxr)then 
        for i:=1 to n do begin
          cx:=xx+mhx[i];
          cy:=yy+mhy[i];
          if (cx<0)or(cy<0)then continue;
          cx:=xx+hx[i];
          cy:=yy+hy[i];
          if (d[cx][cy]=1)then continue;
          dfs2(cx,cy);
        end;
      inc(ko);
      ox[ko]:=xx;
      oy[ko]:=yy;
    end;
begin
  //assign(input,'input.txt');reset(input);
  //assign(output,'output.txt');rewrite(output);
  read(sx,sy,maxr);
  read(n);
  for i:=1 to n do begin
    read(hx[i],hy[i]);
    hx[i]:=hx[i]-i;
    mhx[i]:=-i;
    mhy[i]:=0;
  end;
  read(m);
  for i:=1 to m do begin
    read(hx[n+i],hy[n+i]);
    hy[n+i]:=hy[n+i]-i;
    mhx[n+i]:=0;
    mhy[n+i]:=-i;
  end;
  n:=n+m;
  for i:=0 to maxr do 
    for j:=0 to maxr do d[i][j]:=inf;
  d[sx,sy]:=0;
  qb:=0;qe:=1;
  qx[1]:=sx;qy[1]:=sy;
  while (qb<qe)do begin
    inc(qb);
    xx:=qx[qb];
    yy:=qy[qb];
    for i:=1 to n do begin
      cx:=xx+mhx[i];
      cy:=yy+mhy[i];
      if (cx<0)or(cy<0)then continue;
      cx:=xx+hx[i];
      cy:=yy+hy[i];
      if (cx+cy>maxr)then continue;
      if (d[xx,yy]+1>=d[cx,cy])then continue;
      d[cx,cy]:=d[xx,yy]+1;
      if (cx+cy=0)then continue;
      inc(qe);
      qx[qe]:=cx;
      qy[qe]:=cy;
    end;
  end;
  if (d[0,0]<>inf)then begin
    writeln('Ivan');
    writeln(d[0,0]);
    exit;
  end;
  fillchar(d,sizeof(d),$0);
  dfs(sx,sy);
  ko:=0;
  fillchar(d,sizeof(d),$0);
  dfs2(sx,sy);
  fillchar(d,sizeof(d),$FF);
  d[sx,sy]:=0;
  res:=0;
  for i:=ko-1 downto 1 do begin
    max:=-2;
    xx:=ox[i];
    yy:=oy[i];
    for j:=1 to n do begin
      cx:=xx-hx[j];
      cy:=yy-hy[j];
      if (cx<0)or(cy<0)then continue;
      if (cx+cy>maxr)then continue;
      if (d[cx][cy]=-1)then continue;
      if (d[cx][cy]>max)then max:=d[cx][cy];
    end;
    d[xx][yy]:=max+1;
    if (xx+yy>maxr)and(max+1>res)then begin 
      res:=max+1;
    end;
  end;
  writeln('Zmey');
  writeln(res);
  close(output);close(input);
end.