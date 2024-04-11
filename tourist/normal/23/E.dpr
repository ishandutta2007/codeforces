{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
{$M 30000000}
var
  h,f: array [0..710,0..710] of extended;
  pr: array [0..710,0..710] of longint;
  ans,sz,ss,ff,pred,last: array [0..10010] of longint;
  lg: array [0..710] of extended;
  was: array [0..10010] of boolean;
  len,n,i,m,j: longint;

procedure rec(v:longint);
var
  j,k,q: longint;
begin
  was[v]:=True;
  sz[v]:=1;
  f[v,1]:=0;
  j:=last[v];
  while j > 0 do
  begin
    if not was[ff[j]] then
    begin
      rec(ff[j]);
      for k:=sz[v] downto 1 do
        for q:=sz[ff[j]] downto 0 do
          if f[v,k]+f[ff[j],q] > f[v,k+q] then
            f[v,k+q]:=f[v,k]+f[ff[j],q];
      inc(sz[v],sz[ff[j]]);
    end;
    j:=pred[j];
  end;
  for k:=1 to sz[v] do
    if f[v,k]+lg[k] > f[v,0] then f[v,0]:=f[v,k]+lg[k];
end;

procedure solve(v,w:longint);
var
  ss,t,i,km,kg,j,k,q: longint;
  max: extended;
  g,d: array [0..710] of longint;
begin
  was[v]:=True;
  j:=last[v]; kg:=0;
  while j > 0 do
  begin
    if not was[ff[j]] then inc(kg);
    j:=pred[j];
  end;
  for i:=1 to kg do
    for j:=0 to sz[v] do h[i,j]:=-1e9;
  ss:=1;
  h[0,1]:=0; kg:=0;
  j:=last[v];
  while j > 0 do
  begin
    if not was[ff[j]] then
    begin
      inc(kg);
      g[kg]:=ff[j];
      for k:=ss downto 1 do
        for q:=sz[ff[j]] downto 0 do
          if h[kg-1,k]+f[ff[j],q] > h[kg,k+q] then
          begin
            h[kg,k+q]:=h[kg-1,k]+f[ff[j],q];
            pr[kg,k+q]:=k;
          end;
      inc(ss,sz[ff[j]]);
    end;
    j:=pred[j];
  end;
  if w = 0 then
  begin
    max:=-1e9; km:=0;
    for k:=1 to sz[v] do
      if f[v,k]+lg[k] > max then
      begin
        max:=f[v,k]+lg[k];
        km:=k;
      end;
    t:=0;
    for i:=1 to len do
    begin
      ans[i]:=ans[i]*km+t;
      t:=ans[i] div 10;
      ans[i]:=ans[i]-t*10;
    end;
    while t > 0 do
    begin
      inc(len);
      ans[len]:=t mod 10;
      t:=t div 10;
    end;
    w:=km;
  end;
  for i:=kg downto 1 do
  begin
    d[i]:=w-pr[i,w];
    w:=pr[i,w];
  end;
  for i:=1 to kg do solve(g[i],d[i]);
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  for i:=1 to n do lg[i]:=ln(i);
  m:=n-1;
  for i:=1 to m do read(ss[i],ff[i]);
  fillchar(last,sizeof(last),0);
  for i:=1 to m do
  begin
    ss[i+m]:=ff[i];
    ff[i+m]:=ss[i];
    pred[i]:=last[ss[i]];
    last[ss[i]]:=i;
    pred[i+m]:=last[ff[i]];
    last[ff[i]]:=i+m;
  end;
  for i:=1 to n do
    for j:=0 to n do f[i,j]:=-1e9;
  fillchar(was,sizeof(was),False);
  rec(1);
  fillchar(ans,sizeof(ans),0);
  len:=1; ans[1]:=1;
  fillchar(was,sizeof(was),False);
  solve(1,0);
  for i:=len downto 1 do write(ans[i]);
  writeln;
  close(input);
  close(output);
end.