{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
{$M 50000000}
var
  n,m,i: longint;
  pv,ss,ff,dd,pred,last,sz,tt,s,d,t,a,f: array [0..400010] of int64;
  was: array [0..400010] of boolean;

procedure Sort(l,r:longint);
var
  i,j,pp: longint;
  x,y,tmp: int64;
begin
  i:=l; j:=r;
  pp:=l+random(r-l+1);
  x:=s[pp]; y:=a[pp];
  repeat
    while x*a[i] < y*s[i] do inc(i);
    while x*a[j] > y*s[j] do dec(j);
    if i <= j then
    begin
      tmp:=a[i]; a[i]:=a[j]; a[j]:=tmp;
      tmp:=d[i]; d[i]:=d[j]; d[j]:=tmp;
      tmp:=t[i]; t[i]:=t[j]; t[j]:=tmp;
      tmp:=s[i]; s[i]:=s[j]; s[j]:=tmp;
      inc(i); dec(j);
    end;
  until i > j;
  if l < j then Sort(l,j);
  if i < r then Sort(i,r);
end;

procedure rec(v:longint);
var
  i,j,k: longint;
  r: int64;
begin
  was[v]:=True;
  sz[v]:=1;
  tt[v]:=0;
  j:=last[v];
  while j > 0 do
  begin
    if not was[ff[j]] then
    begin
      pv[ff[j]]:=v;
      rec(ff[j]);
      sz[v]:=sz[v]+sz[ff[j]];
      tt[v]:=tt[v]+tt[ff[j]]+2*dd[j];
    end;
    j:=pred[j];
  end;
  f[v]:=0; k:=0;
  j:=last[v];
  while j > 0 do
  begin
    if pv[ff[j]] = v then
    begin
      f[v]:=f[v]+f[ff[j]];
      inc(k);
      s[k]:=sz[ff[j]];
      d[k]:=dd[j];
      t[k]:=tt[ff[j]];
      a[k]:=2*d[k]+t[k];
    end;
    j:=pred[j];
  end;
  if k = 0 then exit;
  Sort(1,k);
  r:=0;
  for i:=1 to k do
  begin
    f[v]:=f[v]+s[i]*(r+d[i]);
    r:=r+a[i];
  end;
end;

begin
  randseed:=97812;
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  m:=n-1;
  for i:=1 to m do
  begin
    read(ss[i],ff[i],dd[i]);
    ss[i+m]:=ff[i];
    ff[i+m]:=ss[i];
    dd[i+m]:=dd[i];
  end;
  fillchar(last,sizeof(last),0);
  for i:=1 to m+m do
  begin
    pred[i]:=last[ss[i]];
    last[ss[i]]:=i;
  end;
  fillchar(was,sizeof(was),False);
  rec(1);
  writeln(f[1]/(n-1):0:17);
  close(input);
  close(output);
end.