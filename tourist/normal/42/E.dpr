{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
{$M 50000000}
var
  st,ft,pr,pd,pred,last,p,ss,ff,dd: array [0..400010] of longint;
  was: array [0..400010] of boolean;
  f,g: array [0..22,0..100010] of longint;
  cnt,v,nv,tmp,cur,i,it,tt,qq,time,n,m,xx,yy: longint;
  ans: int64;

procedure Sort(l,r:longint);
var
  i,j,x,tmp: longint;
begin
  i:=l; j:=r;
  x:=dd[l+random(r-l+1)];
  repeat
    while dd[i] < x do inc(i);
    while x < dd[j] do dec(j);
    if i <= j then
    begin
      tmp:=ss[i]; ss[i]:=ss[j]; ss[j]:=tmp;
      tmp:=ff[i]; ff[i]:=ff[j]; ff[j]:=tmp;
      tmp:=dd[i]; dd[i]:=dd[j]; dd[j]:=tmp;
      inc(i); dec(j);
    end;
  until i > j;
  if l < j then Sort(l,j);
  if i < r then Sort(i,r);
end;

function findset(x:longint):longint;
begin
  if x <> p[x] then p[x]:=findset(p[x]);
  findset:=p[x];
end;

procedure rec(v:longint);
var
  j: longint;
begin
  was[v]:=True;
  inc(time);
  st[v]:=time;
  j:=last[v];
  while j > 0 do
  begin
    if not was[ff[j]] then
    begin
      pr[ff[j]]:=v;
      pd[ff[j]]:=dd[j];
      rec(ff[j]);
    end;
    j:=pred[j];
  end;
  inc(time);
  ft[v]:=time;
end;

begin
  randseed:=8753;
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,m);
  for i:=1 to m do read(ss[i],ff[i],dd[i]);
  Sort(1,m);
  for i:=1 to n do p[i]:=i;
  ans:=0; cnt:=0;
  for i:=1 to m do
  begin
    xx:=findset(ss[i]);
    yy:=findset(ff[i]);
    if xx <> yy then
    begin
      p[xx]:=yy;
      inc(ans,dd[i]);
      inc(cnt);
      ss[cnt]:=ss[i];
      ff[cnt]:=ff[i];
      dd[cnt]:=dd[i];
    end;
  end;
  m:=cnt;
  if m = n-1 then
  begin
    for i:=1 to m do
    begin
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
    time:=0; pr[1]:=1; pd[1]:=0;
    rec(1);
    for i:=1 to n do
    begin
      f[1,i]:=pr[i];
      g[1,i]:=pd[i];
    end;
    for it:=2 to 19 do
      for i:=1 to n do
      begin
        f[it,i]:=f[it-1,f[it-1,i]];
        g[it,i]:=g[it-1,f[it-1,i]];
        if g[it-1,i] > g[it,i] then g[it,i]:=g[it-1,i];
      end;
  end;
  read(tt);
  for qq:=1 to tt do
  begin
    read(xx,yy);
    if m < n-2 then writeln(-1) else
    if m = n-2 then
    begin
      xx:=findset(xx);
      yy:=findset(yy);
      if xx = yy then writeln(-1)
      else writeln(ans);
    end else
    begin
      cur:=0;
      for i:=1 to 2 do
      begin
        v:=xx; it:=19;
        while ((st[v] > st[yy]) or (ft[v] < ft[yy])) and (it > 0) do
        begin
          nv:=f[it,v];
          if (st[nv] < st[yy]) and (ft[nv] > ft[yy]) then dec(it) else
          begin
            if g[it,v] > cur then cur:=g[it,v];
            v:=nv;
          end;
        end;
        if (st[v] > st[yy]) or (ft[v] < ft[yy]) then
          if pd[v] > cur then cur:=pd[v];
        tmp:=xx; xx:=yy; yy:=tmp;
      end;
      writeln(ans-cur);
    end;
  end;
  close(input);
  close(output);
end.