{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
{$M 50000000}
var
  pp: array [0..20,0..200010] of longint;
  state,id,pe,sz,hang,nv,num,pred,last,tin,tout,ss,ff,pv,p: array [0..200010] of longint;
  zeros,ones: array [0..555555] of longint;
  inv: array [0..555555] of boolean;
  head,dp,ww,d,pd,ps,pf: array [0..200010] of longint;
  h,good,was: array [0..200010] of boolean;
  spec,cntl,tlight,ans,qx,qy,zz,len,rrr,kw,kp,kd,max,km,q,j,xx,yy,root,qq,tt,i,edge,n,m,time: longint;

function findset(x:longint):longint;
begin
  if x <> p[x] then p[x]:=findset(p[x]);
  findset:=p[x];
end;

procedure rec(v:longint);
var
  j: longint;
begin
  inc(kw);
  ww[kw]:=v;
  inc(time);
  tin[v]:=time;
  was[v]:=True;
  sz[v]:=1;
  j:=last[v];
  while j > 0 do
  begin
    if (num[j] <> num[edge]) and (not was[ff[j]]) then
    begin
      pv[ff[j]]:=v;
      pe[ff[j]]:=num[j];
      rec(ff[j]);
      inc(sz[v],sz[ff[j]]);
    end;
    j:=pred[j];
  end;
  inc(time);
  tout[v]:=time;
end;

function lca(x,y:longint):longint;
var
  j,q: longint;
begin
  if (tin[y] >= tin[x]) and (tout[y] <= tout[x]) then lca:=x else
  if (tin[x] >= tin[y]) and (tout[x] <= tout[y]) then lca:=y else
  begin
    for j:=17 downto 0 do
    begin
      q:=pp[j,x];
      if (tin[y] >= tin[q]) and (tout[y] <= tout[q]) then continue;
      x:=q;
    end;
    lca:=pv[x];
  end;
end;

procedure findpath(stt:longint);
var
  j,hd: longint;
begin
  j:=stt;
  inc(kp);
  ps[kp]:=kd+1;
  while h[num[pe[stt]]] do
  begin
    was[stt]:=True;
    inc(kd);
    d[kd]:=num[pe[stt]];
    dp[kd]:=kp;
    pd[d[kd]]:=kd;
    stt:=pv[stt];
  end;
  hd:=stt;
  while j <> hd do
  begin
    head[j]:=hd;
    j:=pv[j];
  end;
  head[hd]:=hd;
  pf[kp]:=kd;
end;

procedure build(x,l,r:longint);
begin
  zeros[x]:=r-l+1;
  ones[x]:=0;
  if l < r then
  begin
    build(x+x,l,(l+r) shr 1);
    build(x+x+1,(l+r) shr 1+1,r);
  end;
end;

function findsum(x,l,r,ll,rr:longint):longint;
var
  tmp: longint;
begin
  if (ll > r) or (l > rr) then findsum:=0 else
  if (l >= ll) and (r <= rr) then findsum:=ones[x] else
  begin
    if inv[x] then
    begin
      tmp:=ones[x+x]; ones[x+x]:=zeros[x+x]; zeros[x+x]:=tmp;
      tmp:=ones[x+x+1]; ones[x+x+1]:=zeros[x+x+1]; zeros[x+x+1]:=tmp;
      inv[x+x]:=not inv[x+x];
      inv[x+x+1]:=not inv[x+x+1];
      inv[x]:=False;
    end;
    findsum:=findsum(x+x,l,(l+r) shr 1,ll,rr)+findsum(x+x+1,(l+r) shr 1+1,r,ll,rr);
  end;
end;

procedure modify(x,l,r,ll,rr:longint);
var
  tmp: longint;
begin
  if (ll > r) or (l > rr) then exit else
  if (l >= ll) and (r <= rr) then
  begin
    tmp:=ones[x]; ones[x]:=zeros[x]; zeros[x]:=tmp;
    inv[x]:=not inv[x];
  end else
  begin
    if inv[x] then
    begin
      tmp:=ones[x+x]; ones[x+x]:=zeros[x+x]; zeros[x+x]:=tmp;
      tmp:=ones[x+x+1]; ones[x+x+1]:=zeros[x+x+1]; zeros[x+x+1]:=tmp;
      inv[x+x]:=not inv[x+x];
      inv[x+x+1]:=not inv[x+x+1];
      inv[x]:=False;
    end;
    modify(x+x,l,(l+r) shr 1,ll,rr);
    modify(x+x+1,(l+r) shr 1+1,r,ll,rr);
    ones[x]:=ones[x+x]+ones[x+x+1];
    zeros[x]:=zeros[x+x]+zeros[x+x+1];
  end;
end;

procedure change(qs,qf:longint);
var
  j,jj: longint;
begin
  while qs <> qf do
    if not h[num[pe[qs]]] then
    begin
      j:=num[pe[qs]];
      dec(tlight,state[j]);
      state[j]:=1-state[j];
      inc(tlight,state[j]);
      qs:=pv[qs];
    end else
    if head[qs] <> head[qf] then
    begin
      j:=num[pe[qs]];
      modify(1,1,kd,pd[j],pf[dp[pd[j]]]);
      qs:=head[qs];
    end else
    begin
      j:=num[pe[qs]];
      jj:=num[pe[qf]];
      if (jj = 0) or (pd[jj] = 0) then modify(1,1,kd,pd[j],pf[dp[pd[j]]])
      else modify(1,1,kd,pd[j],pd[jj]-1);
      qs:=qf;
    end;
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,tt);
  for i:=1 to n do p[i]:=i;
  m:=n;
  edge:=0;
  for i:=1 to m do
  begin
    read(ss[i],ff[i]);
    ss[i+m]:=ff[i];
    ff[i+m]:=ss[i];
    num[i+m]:=i;
    num[i]:=i;
    xx:=findset(ss[i]);
    yy:=findset(ff[i]);
    if xx = yy then edge:=i
    else p[xx]:=yy;
  end;
  fillchar(last,sizeof(last),0);
  for i:=1 to m+m do
  begin
    pred[i]:=last[ss[i]];
    last[ss[i]]:=i;
  end;
  fillchar(was,sizeof(was),False);
  root:=ss[edge];
  pv[0]:=0; pv[root]:=0;
  pe[0]:=0; pe[root]:=0;
  time:=0;
  rec(root);
  tin[0]:=0; tout[0]:=time+1;
  fillchar(good,sizeof(good),False);
  fillchar(head,sizeof(head),0);
  fillchar(nv,sizeof(nv),0);
  good[0]:=True;
  i:=ff[edge];
  nv[i]:=root;
  rrr:=0;
  while i > 0 do
  begin
    good[i]:=True;
    nv[pv[i]]:=i;
    inc(rrr);
    id[i]:=rrr;
    i:=pv[i];
  end;
  fillchar(pp,sizeof(pp),0);
  for i:=1 to n do pp[0,i]:=pv[i];
  for j:=1 to 17 do
    for i:=1 to n do pp[j,i]:=pp[j-1,pp[j-1,i]];
  for i:=1 to n do
    if good[i] then hang[i]:=i else
    begin
      q:=i;
      for j:=17 downto 0 do
        if not good[pp[j,q]] then q:=pp[j,q];
      hang[i]:=pv[q];
    end;
  fillchar(h,sizeof(h),False);
  for i:=1 to n do
    if last[i] > 0 then
    begin
      max:=0; km:=0;
      j:=last[i];
      while j > 0 do
      begin
        if pv[ff[j]] = i then
        begin
          if good[ff[j]] then
          begin
            h[num[j]]:=True;
            km:=0;
            break;
          end;
          if sz[ff[j]] > max then
          begin
            max:=sz[ff[j]];
            km:=j;
          end;
        end;
        j:=pred[j];
      end;
      if (not good[i]) and (km > 0) then h[num[km]]:=True;
    end;
  fillchar(was,sizeof(was),False);
  kd:=0; kp:=0;
  findpath(ff[edge]);
  for j:=n downto 1 do
  begin
    i:=ww[j];
    if (i <> ff[edge]) and (h[num[pe[i]]]) and (not was[i]) then findpath(i);
  end;
  cntl:=-1;
  for i:=1 to m do
    if not h[i] then
    begin
      state[i]:=0;
      inc(cntl);
    end;
  spec:=0;
  tlight:=0;
  fillchar(zeros,sizeof(zeros),0);
  fillchar(ones,sizeof(ones),0);
  build(1,1,kd);
  for qq:=1 to tt do
  begin
    read(xx,yy);
    if xx <> yy then
    begin
      if hang[xx] = hang[yy] then
      begin
        zz:=lca(xx,yy);
        if xx <> zz then change(xx,zz);
        if yy <> zz then change(yy,zz);
      end else
      begin
        change(xx,hang[xx]);
        change(yy,hang[yy]);
        len:=id[root];
        qx:=id[hang[xx]];
        qy:=id[hang[yy]];
        if abs(qx-qy)*2 = len then
        begin
          pv[root]:=ff[edge];
          if nv[hang[xx]] > pv[hang[xx]] then
          begin
            if qx > qy then
            begin
              change(ff[edge],hang[yy]);
              change(hang[xx],root);
              spec:=1-spec;
            end
            else change(hang[xx],hang[yy]);
          end else
          begin
            if qy > qx then
            begin
              change(ff[edge],hang[xx]);
              change(hang[yy],root);
              spec:=1-spec;
            end
            else change(hang[yy],hang[xx]);
          end;
        end else
        if abs(qx-qy)*2 < len then
        begin
          if tin[hang[xx]] < tin[hang[yy]] then change(hang[yy],hang[xx])
          else change(hang[xx],hang[yy]);
        end else
        begin
          spec:=1-spec;
          if qx < qy then
          begin
            change(ff[edge],hang[xx]);
            change(hang[yy],root);
          end else
          begin
            change(ff[edge],hang[yy]);
            change(hang[xx],root);
          end;
        end;
      end;
    end;
    ans:=zeros[1]+1+cntl-tlight;
    if spec = 1 then
      if findsum(1,1,kd,1,pf[1]) < pf[1] then dec(ans);
    writeln(ans);
  end;
  close(input);
  close(output);
end.