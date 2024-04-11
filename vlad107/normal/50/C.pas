{$r-,q-,s-,i-,o+}
const
  MAXN=500100;

var
  res:int64;
  mx,kx,ky,xx,yy,m,n,tt,i,j,sa,sb,p1,p2:longint;
  a,b,x,y,x2,y2:array[1..MAXN]of longint;

  function cw(x1,y1,x2,y2,x3,y3:int64):boolean;
    begin
      cw:=x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)<0;
    end;

  function ccw(x1,y1,x2,y2,x3,y3:int64):boolean;
    begin
      ccw:=x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)>0;
    end;

  procedure qs(l,r:longint);
    var
      i,j,xx,yy,tmp:longint;

    begin
      i:=l;j:=r;
      xx:=x[(i+j)shr 1];
      yy:=y[(i+j)shr 1];
      while (i<=j) do begin
        while (xx<x[i])or(xx=x[i])and(yy>y[i])do inc(i);
        while (xx>x[j])or(xx=x[j])and(yy<y[j])do dec(j);
        if (i>j)then break;
        tmp:=x[i];x[i]:=x[j];x[j]:=tmp;
        tmp:=y[i];y[i]:=y[j];y[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<r)then qs(i,r);
      if (j>l)then qs(l,j);
    end;

begin
  read(tt);
  n:=0;
  while (tt>0) do begin
    dec(tt);
    read(xx,yy);
    inc(n);x[n]:=xx+1;y[n]:=yy;
    inc(n);x[n]:=xx-1;y[n]:=yy;
    inc(n);x[n]:=xx;y[n]:=yy+1;
    inc(n);x[n]:=xx;y[n]:=yy-1;
  end;
  qs(1,n);
  p1:=1;p2:=n;
  sa:=1;sb:=1;
  a[sa]:=1;
  b[sb]:=1;
  for i:=2 to n do begin
    if (i=n)or(cw(x[p1],y[p1],x[i],y[i],x[p2],y[p2]))then begin
      while (sa>1)and(not cw(x[a[sa-1]],y[a[sa-1]],x[a[sa]],y[a[sa]],x[i],y[i]))
        do dec(sa);
      inc(sa);
      a[sa]:=i;
    end else begin
      while (sb>1)and(not ccw(x[b[sb-1]],y[b[sb-1]],x[b[sb]],y[b[sb]],x[i],y[i]))
        do dec(sb);
      inc(sb);
      b[sb]:=i;
    end;
  end;
  m:=0;
  for i:=1 to sa do begin
    inc(m);
    x2[m]:=x[a[i]];
    y2[m]:=y[a[i]];
  end;
  for i:=sb-1 downto 1 do begin
    inc(m);
    x2[m]:=x[b[i]];
    y2[m]:=y[b[i]];
  end;
  n:=m;
  x:=x2;y:=y2;
  res:=0;
  for i:=1 to n do begin
    j:=(i mod n) + 1;
    kx:=abs(x[i]-x[j]);
    ky:=abs(y[i]-y[j]);
    if (kx<ky)then mx:=kx else mx:=ky;
    inc(res,kx+ky-mx);
  end;
  writeln(res);
end.