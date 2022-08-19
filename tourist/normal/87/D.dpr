{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
{$M 50000000}
var
  pv,s,p,sz,num,rs,rv,qs,qf,qd,qn,ss,ff,pred,last,e,pe: array [0..400010] of longint;
  was: array [0..400010] of boolean;
  ans: array [0..400010] of int64;
  max: int64;
  tot,ks,n,mm,m,ii,jj,i,j,ke,u,t: longint;

procedure Sort(l,r:longint);
var
  i,j,x,tmp: longint;
begin
  i:=l; j:=r;
  x:=qd[l+random(r-l+1)];
  repeat
    while qd[i] < x do inc(i);
    while x < qd[j] do dec(j);
    if i <= j then
    begin
      tmp:=qs[i]; qs[i]:=qs[j]; qs[j]:=tmp;
      tmp:=qf[i]; qf[i]:=qf[j]; qf[j]:=tmp;
      tmp:=qd[i]; qd[i]:=qd[j]; qd[j]:=tmp;
      tmp:=qn[i]; qn[i]:=qn[j]; qn[j]:=tmp;
      inc(i); dec(j);
    end;
  until i > j;
  if l < j then Sort(l,j);
  if i < r then Sort(i,r);
end;

procedure SortE(l,r:longint);
var
  i,j,x,tmp: longint;
begin
  i:=l; j:=r;
  x:=e[l+random(r-l+1)];
  repeat
    while e[i] < x do inc(i);
    while x < e[j] do dec(j);
    if i <= j then
    begin
      tmp:=e[i]; e[i]:=e[j]; e[j]:=tmp;
      tmp:=pe[i]; pe[i]:=pe[j]; pe[j]:=tmp;
      inc(i); dec(j);
    end;
  until i > j;
  if l < j then SortE(l,j);
  if i < r then SortE(i,r);
end;

function rec(v:longint):longint;
var
  j,sum,cur: longint;
begin
  was[v]:=True;
  sum:=rs[v];
  j:=last[v];
  while j > 0 do
  begin
    if not was[ff[j]] then
    begin
      pv[ff[j]]:=v;
      cur:=rec(ff[j]);
      inc(sum,cur);
    end;
    j:=pred[j];
  end;
  rec:=sum;
end;

function rec2(v:longint):longint;
var
  j,sum,cur: longint;
begin
  sum:=rs[v];
  j:=last[v];
  while j > 0 do
  begin
    if pv[ff[j]] = v then
    begin
      pv[ff[j]]:=v;
      cur:=rec2(ff[j]);
      ans[num[j]]:=int64(cur)*(tot-cur);
      inc(sum,cur);
    end;
    j:=pred[j];
  end;
  rec2:=sum;
end;

function findset(x:longint):longint;
begin
  if x <> p[x] then p[x]:=findset(p[x]);
  findset:=p[x];
end;

begin
  randseed:=8753;
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  mm:=n-1;
  for i:=1 to mm do
  begin
    read(qs[i],qf[i],qd[i]);
    qn[i]:=i;
    ans[i]:=0;
  end;
  Sort(1,mm);
  for i:=1 to n do
  begin
    p[i]:=i;
    sz[i]:=1;
  end;
  ii:=1;
  while ii <= mm do
  begin
    jj:=ii;
    while (jj <= mm) and (qd[ii] = qd[jj]) do inc(jj);
    m:=0;
    for u:=ii to jj-1 do
    begin
      inc(m);
      ss[m]:=findset(qs[u]);
      ff[m]:=findset(qf[u]);
      num[m]:=qn[u];
    end;
    ke:=0;
    for i:=1 to m do
    begin
      inc(ke);
      e[ke]:=ss[i];
      pe[ke]:=i;
      inc(ke);
      e[ke]:=ff[i];
      pe[ke]:=-i;
    end;
    SortE(1,ke);
    t:=0;
    for i:=1 to ke do
    begin
      if (i = 1) or (e[i] <> e[i-1]) then
      begin
        inc(t);
        rv[t]:=e[i];
        rs[t]:=sz[e[i]];
      end;
      if pe[i] > 0 then ss[pe[i]]:=t
      else ff[-pe[i]]:=t;
    end;
    for i:=1 to m do
    begin
      ss[i+m]:=ff[i];
      ff[i+m]:=ss[i];
      num[i+m]:=num[i];
    end;
    for i:=1 to t do last[i]:=0;
    for i:=1 to m+m do
    begin
      pred[i]:=last[ss[i]];
      last[ss[i]]:=i;
    end;
    for i:=1 to t do was[i]:=False;
    for i:=1 to t do pv[i]:=0;
    for i:=1 to t do
      if not was[i] then
      begin
        tot:=rec(i);
        rec2(i);
      end;
    for u:=ii to jj-1 do
    begin
      i:=findset(qs[u]);
      j:=findset(qf[u]);
      if random(2) = 0 then
      begin
        p[i]:=j;
        inc(sz[j],sz[i]);
      end else
      begin
        p[j]:=i;
        inc(sz[i],sz[j]);
      end;
    end;
    ii:=jj;
  end;
  max:=-1;
  for i:=1 to mm do
    if ans[i] > max then max:=ans[i];
  write(max*2,' ');
  ks:=0;
  for i:=1 to mm do
    if ans[i] = max then
    begin
      inc(ks);
      s[ks]:=i;
    end;
  writeln(ks);
  for i:=1 to ks-1 do write(s[i],' ');
  writeln(s[ks]);
  close(input);
  close(output);
end.