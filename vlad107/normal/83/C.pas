{$r-,q-,s-,i-,o+}
//{$ASSERTIONS on}
const
  inf=1000000000;
  hx:array[1..4]of longint=(1,0,-1,0);
  hy:array[1..4]of longint=(0,1,0,-1);
var
  cr,res:ansistring;
  k,m,dl,kt,n,sx,sy,ex,ey,x,y,cx,cy,t,qb,qe,i,j,qe2:longint;
  minch:char;
  qx,qy,qx2,qy2:array[0..1005000]of longint;
  a:array[0..500,0..500]of char;
  d:array[0..500,0..500]of longint;
  used:array[0..500,0..500]of boolean;
  abc:array[0..5]of char;
  procedure solve;
    var
      i,j:longint;
    begin
      qb:=0;qe:=1;
      for i:=1 to n do 
        for j:=1 to m do d[i][j]:=inf;
      d[ex][ey]:=-1;
      qx[1]:=ex;
      qy[1]:=ey;
      while (qb<qe)do begin
        inc(qb);
        x:=qx[qb];
        y:=qy[qb];
        for i:=1 to 4 do begin
          cx:=x+hx[i];
          cy:=y+hy[i];
          if (cx<1)or(cy<1)or(cx>n)or(cy>m)then continue;                                 
          if (a[cx][cy]<>abc[1])and(a[cx][cy]<>abc[2])and(a[cx][cy]<>abc[3])and(a[cx][cy]<>abc[4])and(a[cx][cy]<>'S')then continue;
          if (d[x][y]+1>=d[cx][cy])then continue;
          d[cx][cy]:=d[x][y]+1;
          inc(qe);
          qx[qe]:=cx;
          qy[qe]:=cy;
        end;
      end;
      if (d[sx][sy]>dl)then exit;
      qe:=1;
      qx[1]:=sx;
      qy[1]:=sy;
      cr:='';
      for i:=1 to n do for j:=1 to m do used[i][j]:=false;
      for i:=1 to d[sx][sy] do begin
        minch:=#255;
        for j:=1 to qe do begin
          x:=qx[j];y:=qy[j];
          for t:=1 to 4 do begin
            cx:=x+hx[t];
            cy:=y+hy[t];
            if (cx<1)or(cy<1)or(cx>n)or(cy>m)then continue;
            if (used[cx][cy])then continue;
            if (d[x][y]-1<>d[cx][cy])then continue;
            if (a[cx][cy]<minch)then minch:=a[cx][cy];
          end;
        end;
        qe2:=0;
        cr:=cr+minch;
        for j:=1 to qe do begin
          x:=qx[j];y:=qy[j];
          for t:=1 to 4 do begin
            cx:=x+hx[t];
            cy:=y+hy[t];
            if (cx<1)or(cy<1)or(cx>n)or(cy>m)then continue;
            if (d[x][y]-1<>d[cx][cy])then continue;
            if (used[cx][cy])then continue;
            if (a[cx][cy]<>minch)then continue;
            inc(qe2);
            qx2[qe2]:=cx;
            qy2[qe2]:=cy;
            used[cx][cy]:=true;
          end;
        end;
        qe:=qe2;
        for j:=1 to qe do begin
          qx[j]:=qx2[j];
          qy[j]:=qy2[j];
        end;
      end;
      if (d[sx][sy]=dl)and(cr>res)then exit;
      dl:=d[sx][sy];
      res:=cr;
    end;
  procedure rec(last:longint);
    var
      i:longint;
    begin
      if (kt=k)then begin
        solve;
        exit;
      end;
      for i:=last+1 to 26 do begin
        inc(kt);
        abc[kt]:=chr(96+i);
        rec(i);
        dec(kt);
      end;
    end;
begin
{  assign(input,'input.txt');reset(input);
  assign(output,'output.txt');rewrite(output);}
  readln(n,m,k);
  for i:=1 to n do begin
    for j:=1 to m do begin
      read(a[i][j]);
      if (a[i][j]='T')then begin
        ex:=i;ey:=j;
      end;
      if (a[i][j]='S')then begin
        sx:=i;sy:=j;
      end;
    end;
    readln;
  end;
  kt:=0;
  dl:=inf-100;
  res:=#255;
  rec(0);
  if (dl=inf-100)then begin
    writeln(-1);
    exit;
  end;
  writeln(res);
end.