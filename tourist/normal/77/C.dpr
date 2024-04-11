{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
{$M 50000000}
var
  b,ss,ff,pred,last,pv,t,tt,f,r: array [0..200010] of int64;
  was: array [0..200010] of boolean;
  st,m,n,i: longint;

procedure Sort(l,r:longint);
var
  i,j: longint;
  x,tmp: int64;
begin
  i:=l; j:=r;
  x:=t[l+random(r-l+1)];
  repeat
    while t[i] > x do inc(i);
    while x > t[j] do dec(j);
    if i <= j then
    begin
      tmp:=t[i]; t[i]:=t[j]; t[j]:=tmp;
      tmp:=tt[i]; tt[i]:=tt[j]; tt[j]:=tmp;
      inc(i); dec(j);
    end;
  until i > j;
  if l < j then Sort(l,j);
  if i < r then Sort(i,r);
end;

procedure rec(v:longint);
var
  j,kt: longint;
  s: int64;
begin
  was[v]:=True;
  j:=last[v];
  while j > 0 do
  begin
    if not was[ff[j]] then
    begin
      pv[ff[j]]:=v;
      rec(ff[j]);
    end;
    j:=pred[j];
  end;
  kt:=0;
  j:=last[v];
  while j > 0 do
  begin
    if pv[ff[j]] = v then
    begin
      inc(kt);
      t[kt]:=f[ff[j]];
      tt[kt]:=r[ff[j]];
    end;
    j:=pred[j];
  end;
  if kt > 0 then Sort(1,kt);
  if b[v] <= kt then
  begin
    f[v]:=0;
    for j:=1 to b[v] do inc(f[v],t[j]+2);
    r[v]:=0;
  end else
  begin
    f[v]:=0;
    for j:=1 to kt do inc(f[v],t[j]+2);
    s:=0;
    for j:=1 to kt do inc(s,tt[j]);
    r[v]:=0;
    if s > b[v]-kt then inc(f[v],(b[v]-kt)*2) else
    begin
      inc(f[v],s*2);
      r[v]:=b[v]-kt-s;
    end;
  end;
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  for i:=1 to n do read(b[i]);
  for i:=1 to n do dec(b[i]);
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
  read(st);
  inc(b[st]);
  fillchar(was,sizeof(was),False);
  rec(st);
  writeln(f[st]);
  close(input);
  close(output);
end.