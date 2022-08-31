{$R-,S-,Q-,I-,O+}
{$M 50000000}
var
  x,y,pv,ss,ff,pred,last,sz,vx,vy,a,tree,ans: array [0..11111] of longint;
  was: array [0..11111] of boolean;
  n,m,i,j,km: longint;

procedure rec(v:longint);
var
  j: longint;
begin
  was[v]:=True;
  sz[v]:=1;
  j:=last[v];
  while j > 0 do
  begin
    if not was[ff[j]] then
    begin
      pv[ff[j]]:=v;
      rec(ff[j]);
      inc(sz[v],sz[ff[j]]);
    end;
    j:=pred[j];
  end;
end;

procedure Sort(l,r:longint);
var
  i,j,pp,x,y,tmp: longint;
begin
  i:=l; j:=r;
  pp:=l+random(r-l+1);
  x:=vx[pp]; y:=vy[pp];
  repeat
    while int64(vx[i])*y-int64(vy[i])*x < 0 do inc(i);
    while int64(vx[j])*y-int64(vy[j])*x > 0 do dec(j);
    if i <= j then
    begin
      tmp:=vx[i]; vx[i]:=vx[j]; vx[j]:=tmp;
      tmp:=vy[i]; vy[i]:=vy[j]; vy[j]:=tmp;
      tmp:=a[i]; a[i]:=a[j]; a[j]:=tmp;
      inc(i); dec(j);
    end;
  until i > j;
  if l < j then Sort(l,j);
  if i < r then Sort(i,r);
end;

procedure go(v,l,r:longint);
var
  i,j: longint;
begin
  tree[l]:=v;
  if l = r then exit;
  for i:=l+1 to r do
  begin
    vx[i]:=x[a[i]]-x[a[l]];
    vy[i]:=y[a[i]]-y[a[l]];
  end;
  Sort(l+1,r);
  i:=l+1;
  j:=last[v];
  while j > 0 do
  begin
    if pv[ff[j]] = v then
    begin
      go(ff[j],i,i+sz[ff[j]]-1);
      i:=i+sz[ff[j]];
    end;
    j:=pred[j];
  end;
end;

begin
  randomize;
  read(n);
  m:=n-1;
  for i:=1 to m do
  begin
    read(ss[i],ff[i]);
    ss[i+m]:=ff[i];
    ff[i+m]:=ss[i];
  end;
  fillchar(last,sizeof(last),0);
  for i:=1 to m+m do
  begin
    pred[i]:=last[ss[i]];
    last[ss[i]]:=i;
  end;
  fillchar(was,sizeof(was),False);
  pv[1]:=0;
  rec(1);
  for i:=1 to n do read(x[i],y[i]);
  km:=1;
  for i:=2 to n do
    if (y[i] < y[km]) or (y[i] = y[km]) and (x[i] < x[km]) then km:=i;
  a[1]:=km; j:=1;
  for i:=1 to n do
    if i <> km then
    begin
      inc(j);
      a[j]:=i;
    end;
  go(1,1,n);
  for i:=1 to n do ans[a[i]]:=tree[i];
  for i:=1 to n-1 do write(ans[i],' ');
  writeln(ans[n]);
end.