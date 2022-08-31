{$R-,S-,Q-,I-,O+}
const eps = 1e-9;
var
  n,i: longint;
  ans: extended;
  x1,y1,x2,y2,x3,y3: array [0..1111] of int64;
  px: array [0..1111] of longint;
  x: array [0..1111] of extended;

procedure go(xt1,yt1,xt2,yt2:int64;id:longint);
var
  a,b,c: int64;
  tt,bal,m,i,j,kx: longint;
  len,tmp: extended;
  xm: array [0..9] of extended;

procedure checkpoint(x,y:int64);
var
  z: int64;
begin
  z:=a*x+b*y+c;
  if z = 0 then
  begin
    inc(m);
    xm[m]:=sqrt(1.0*((x-xt1)*(x-xt1)+(y-yt1)*(y-yt1)));
    if (x < xt1) and (xt2 > xt1) or (x > xt1) and (xt2 < xt1) or
       (y < yt1) and (yt2 > yt1) or (y > yt1) and (yt2 < yt1) then
      xm[m]:=-xm[m];
  end;
end;

procedure checkpointfl(x,y:extended);
begin
  inc(m);
  xm[m]:=sqrt(1.0*((x-xt1)*(x-xt1)+(y-yt1)*(y-yt1)));
  if (x+eps < xt1) and (xt2 > xt1) or (x-eps > xt1) and (xt2 < xt1) or
     (y+eps < yt1) and (yt2 > yt1) or (y-eps > yt1) and (yt2 < yt1) then
    xm[m]:=-xm[m];
end;

procedure checkside(x1,y1,x2,y2:int64);
var
  z1,z2,aa,bb,cc,d,dx,dy: int64;
begin
  z1:=a*x1+b*y1+c;
  z2:=a*x2+b*y2+c;
  if (z1 = 0) or (z2 = 0) then exit;
  if (z1 < 0) and (z2 < 0) then exit;
  if (z1 > 0) and (z2 > 0) then exit;
  aa:=y2-y1;
  bb:=x1-x2;
  cc:=-aa*x1-bb*y1;
  d:=a*bb-b*aa;
  if d = 0 then exit;
  dx:=b*cc-c*bb;
  dy:=c*aa-a*cc;
  checkpointfl(1.0*dx/d,1.0*dy/d);
end;

begin
  a:=yt2-yt1;
  b:=xt1-xt2;
  c:=-a*xt1-b*yt1;
  len:=sqrt(1.0*((xt1-xt2)*(xt1-xt2)+(yt1-yt2)*(yt1-yt2)));
  kx:=0;
  for i:=1 to n do
  begin
    if i = id then continue;
    m:=0;
    checkpoint(x1[i],y1[i]);
    checkpoint(x2[i],y2[i]);
    checkpoint(x3[i],y3[i]);
    checkside(x1[i],y1[i],x2[i],y2[i]);
    checkside(x1[i],y1[i],x3[i],y3[i]);
    checkside(x3[i],y3[i],x2[i],y2[i]);
    if m = 2 then
    begin
      if xm[1] > xm[2] then
      begin
        tmp:=xm[1];
        xm[1]:=xm[2];
        xm[2]:=tmp;
      end;
      if xm[1]+eps > xm[2] then continue;
      if (xm[2] < eps) or (xm[1] > len-eps) then continue;
      if xm[1] < 0 then xm[1]:=0;
      if xm[2] > len then xm[2]:=len;
      inc(kx);
      x[kx]:=xm[1];
      px[kx]:=1;
      inc(kx);
      x[kx]:=xm[2];
      px[kx]:=-1;
    end;
  end;
  ans:=ans+len;
  for i:=1 to kx-1 do
    for j:=i+1 to kx do
      if x[i] > x[j] then
      begin
        tmp:=x[i]; x[i]:=x[j]; x[j]:=tmp;
        tt:=px[i]; px[i]:=px[j]; px[j]:=tt;
      end;
  bal:=0;
  for i:=1 to kx-1 do
  begin
    inc(bal,px[i]);
    if bal > 0 then ans:=ans-(x[i+1]-x[i]);
  end;
end;

begin
  read(n);
  for i:=1 to n do read(x1[i],y1[i],x2[i],y2[i],x3[i],y3[i]);
  ans:=0;
  for i:=1 to n do
  begin
    go(x1[i],y1[i],x2[i],y2[i],i);
    go(x1[i],y1[i],x3[i],y3[i],i);
    go(x3[i],y3[i],x2[i],y2[i],i);
  end;
  writeln(ans:0:17);
end.