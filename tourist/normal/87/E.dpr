{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
var
  xt,yt,x,y: array [0..400010] of int64;
  zt: array [0..400010] of longint;
  vx,vy: array [0..4] of int64;
  p,nn: array [0..4] of longint;
  xn,yn: array [0..4,0..400010] of int64;
  res: array [0..400010] of boolean;
  a,b,c,z,xx,yy: int64;
  pd,pu,ld,rd,lu,ru,mm,m,q,km,i,n: longint;

function mul(a,b:int64):int64;
var
  c: int64;
  z: boolean;
begin
  z:=False;
  if a < 0 then begin a:=-a; z:=not z; end;
  if b < 0 then begin b:=-b; z:=not z; end;
  c:=a*b;
  if z then c:=-c;
  mul:=c;
end;

function less(q,w:longint):boolean;
var
  u,v: int64;
begin
  if p[w] > nn[w] then less:=True else
  begin
    u:=mul(vx[q],vy[w]);
    v:=mul(vy[q],vx[w]);
    if u > v then less:=True
    else less:=False;
  end;
end;

procedure Sort(l,r:longint);
var
  i,j,tt: longint;
  x,tmp: int64;
begin
  i:=l; j:=r;
  x:=xt[l+random(r-l+1)];
  repeat
    while xt[i] < x do inc(i);
    while x < xt[j] do dec(j);
    if i <= j then
    begin
      tmp:=xt[i]; xt[i]:=xt[j]; xt[j]:=tmp;
      tmp:=yt[i]; yt[i]:=yt[j]; yt[j]:=tmp;
      tt:=zt[i]; zt[i]:=zt[j]; zt[j]:=tt;
      inc(i); dec(j);
    end;
  until i > j;
  if l < j then Sort(l,j);
  if i < r then Sort(i,r);
end;

begin
  randseed:=8753;
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  for q:=1 to 3 do
  begin
    read(nn[q]);
    km:=1;
    for i:=1 to nn[q] do
    begin
      read(xn[q,i],yn[q,i]);
      if (yn[q,i] < yn[q,km]) or (yn[q,i] = yn[q,km]) and (xn[q,i] < xn[q,km]) then km:=i;
      xn[q,i+nn[q]]:=xn[q,i];
      yn[q,i+nn[q]]:=yn[q,i];
      xn[q,i+nn[q]+nn[q]]:=xn[q,i];
      yn[q,i+nn[q]+nn[q]]:=yn[q,i];
    end;
    for i:=km to km+nn[q]+nn[q] do
    begin
      xn[q,i-km+1]:=xn[q,i];
      yn[q,i-km+1]:=yn[q,i];
    end;
  end;
  for i:=1 to 3 do p[i]:=1;
  n:=1;
  x[1]:=xn[1,1]+xn[2,1]+xn[3,1];
  y[1]:=yn[1,1]+yn[2,1]+yn[3,1];
  while (p[1] <= nn[1]) or (p[2] <= nn[2]) or (p[3] <= nn[3]) do
  begin
    for i:=1 to 3 do
    begin
      vx[i]:=xn[i,p[i]+1]-xn[i,p[i]];
      vy[i]:=yn[i,p[i]+1]-yn[i,p[i]];
    end;
    if (p[1] <= nn[1]) and less(1,2) and less(1,3) then q:=1 else
    if (p[2] <= nn[2]) and less(2,3) then q:=2
    else q:=3;
    inc(n);
    x[n]:=x[n-1]+vx[q];
    y[n]:=y[n-1]+vy[q];
    inc(p[q]);
  end;
  ld:=1; lu:=1;
  rd:=1; ru:=1;
  for i:=1 to n do
  begin
    if (x[i] < x[ld]) or (x[i] = x[ld]) and (y[i] < y[ld]) then ld:=i;
    if (x[i] < x[lu]) or (x[i] = x[lu]) and (y[i] > y[lu]) then lu:=i;
    if (x[i] > x[rd]) or (x[i] = x[rd]) and (y[i] < y[rd]) then rd:=i;
    if (x[i] > x[ru]) or (x[i] = x[ru]) and (y[i] > y[ru]) then ru:=i;
  end;
  read(mm);
  m:=0;
  for i:=1 to mm do
  begin
    read(xx,yy);
    xx:=xx*3; yy:=yy*3;
    if (xx < x[ld]) or (xx > x[rd]) then res[i]:=False else
    if xx = x[ld] then res[i]:=(yy >= y[ld]) and (yy <= y[lu]) else
    if xx = x[rd] then res[i]:=(yy >= y[rd]) and (yy <= y[ru]) else
    begin
      inc(m);
      xt[m]:=xx;
      yt[m]:=yy;
      zt[m]:=i;
    end;
  end;
  if m > 0 then
  begin
    Sort(1,m);
    i:=1;
    while i <= m do
    begin
      pd:=ld+1;
      if pd > n then pd:=1;
      pu:=lu-1;
      if pu < 1 then pu:=n;
      if x[pd] < xt[i] then ld:=pd else
      if x[pu] < xt[i] then lu:=pu else
      begin
        a:=y[pd]-y[ld];
        b:=x[ld]-x[pd];
        c:=-mul(a,x[ld])-mul(b,y[ld]);
        z:=mul(a,xt[i])+mul(b,yt[i]);
        if z > -c then res[zt[i]]:=False else
        begin
          a:=y[pu]-y[lu];
          b:=x[lu]-x[pu];
          c:=-mul(a,x[lu])-mul(b,y[lu]);
          z:=mul(a,xt[i])+mul(b,yt[i]);
          res[zt[i]]:=z >= -c;
        end;
        inc(i);
      end;
    end;
  end;
  for i:=1 to mm do
    if res[i] then writeln('YES')
    else writeln('NO');
  close(input);
  close(output);
end.