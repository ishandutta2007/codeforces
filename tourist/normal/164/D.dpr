{$R-,S-,Q-,I-,O+}
{$M 10000000}
var
  d,di,dj: array [0..500010] of longint;
  last,pred,kg,res,deg,b,rd,xx,yy: array [0..1010] of longint;
  good: array [0..500010] of boolean;
  ss,ff: array [0..500010] of longint;
  pz: array [0..1010,0..1010] of longint;
  g: array [0..1010,0..33] of longint;
  gv: array [0..1010] of boolean;
  ok,found: boolean;
  cnt,need,k,nn,n,ll,rr,mid,i,j,m: longint;

procedure Sort(l,r:longint);
var
  i,j,x,tmp: longint;
begin
  i:=l; j:=r;
  x:=d[l+random(r-l+1)];
  repeat
    while d[i] > x do inc(i);
    while x > d[j] do dec(j);
    if i <= j then
    begin
      tmp:=d[i]; d[i]:=d[j]; d[j]:=tmp;
      tmp:=di[i]; di[i]:=di[j]; di[j]:=tmp;
      tmp:=dj[i]; dj[i]:=dj[j]; dj[j]:=tmp;
      inc(i); dec(j);
    end;
  until i > j;
  if l < j then Sort(l,j);
  if i < r then Sort(i,r);
end;

procedure rec(nd,cc:longint);
var
  ii,qr,ncc,nnd,i,j,q,mx,km: longint;
  rq: array [0..33] of longint;
begin
  if found then exit;
  if cc = 0 then
  begin
    for i:=1 to n do
      if gv[i] and (nd > 0) then
      begin
        res[nd]:=i;
        dec(nd);
      end;
    found:=True;
    exit;
  end;
  if nd = 0 then exit;
  mx:=-100; km:=0;
  for i:=1 to nn do
    if gv[b[i]] then
      if rd[i] <= mx then break else
      if deg[b[i]] > mx then
      begin
        mx:=deg[b[i]];
        km:=b[i];
      end;
  if cc > nd*mx then exit;

  for i:=1 to kg[km] do
    if gv[g[km,i]] then dec(deg[g[km,i]]);
  gv[km]:=False;
  deg[km]:=0;
  res[nd]:=km;
  rec(nd-1,cc-mx);
  if found then exit;
  res[nd]:=0;
  deg[km]:=mx;
  gv[km]:=True;
  for i:=1 to kg[km] do
    if gv[g[km,i]] then inc(deg[g[km,i]]);

  nnd:=nd; ncc:=cc;
  qr:=0;
  for i:=1 to kg[km] do
  begin
    j:=g[km,i];
    if gv[j] then
    begin
      res[nnd]:=j;
      dec(nnd);
      if nnd < 0 then break;
      for q:=1 to kg[j] do
        if gv[g[j,q]] then
        begin
          dec(ncc);
          dec(deg[g[j,q]]);
          dec(deg[j]);
        end;
      inc(qr);
      rq[qr]:=i;
      gv[j]:=False;
    end;
  end;
  if nnd >= 0 then rec(nnd,ncc);
  if found then exit;
  for ii:=qr downto 1 do
  begin
    i:=rq[ii];
    j:=g[km,i];
    gv[j]:=True;
    for q:=1 to kg[j] do
      if gv[g[j,q]] then
      begin
        inc(deg[g[j,q]]);
        inc(deg[j]);
      end;
  end;
end;

begin
  randomize;
  read(n,k);
  for i:=1 to n do read(xx[i],yy[i]);
  m:=0;
  for i:=1 to n-1 do
    for j:=i+1 to n do
    begin
      inc(m);
      d[m]:=(xx[i]-xx[j])*(xx[i]-xx[j])+(yy[i]-yy[j])*(yy[i]-yy[j]);
      di[m]:=i;
      dj[m]:=j;
    end;
  Sort(1,m);
  for i:=1 to m do
  begin
    pz[di[i],dj[i]]:=i;
    pz[dj[i],di[i]]:=i;
  end;
  for i:=1 to n do pz[i,i]:=m+1;
  ll:=1; rr:=(n*(n-1) div 2)-((n-k)*(n-k-1) div 2);
  while ll <= rr do
  begin
    mid:=(ll+rr+1) shr 1;
    for i:=1 to n do deg[i]:=0;
    for i:=1 to mid do
    begin
      inc(deg[di[i]]);
      inc(deg[dj[i]]);
      good[i]:=True;
    end;
    for i:=1 to n do gv[i]:=True;
    need:=k;
    while need > 0 do
    begin
      ok:=False;
      for i:=1 to n do
        if gv[i] and (deg[i] > need) then
        begin
          for j:=1 to n do
            if (pz[i,j] <= mid) and (good[pz[i,j]]) then
            begin
              dec(deg[j]);
              good[pz[i,j]]:=False;
            end;
          deg[i]:=0;
          res[need]:=i;
          gv[i]:=False;
          ok:=True;
          break;
        end;
      if not ok then break;
      dec(need);
    end;
    j:=0;
    for i:=1 to mid do
      if good[i] then
      begin
        inc(j);
        ss[j]:=di[i];
        ff[j]:=dj[i];
      end;
    cnt:=j;
    if cnt > need*need then rr:=mid-1 else
    begin
      for i:=0 to need do last[i]:=0;
      for i:=1 to n do
      begin
        pred[i]:=last[deg[i]];
        last[deg[i]]:=i;
      end;
      nn:=0;
      for i:=need downto 1 do
      begin
        j:=last[i];
        while j > 0 do
        begin
          inc(nn);
          b[nn]:=j;
          rd[nn]:=i;
          j:=pred[j];
        end;
      end;
      for i:=1 to n do kg[i]:=0;
      for i:=1 to cnt do
      begin
        inc(kg[ss[i]]);
        g[ss[i],kg[ss[i]]]:=ff[i];
        inc(kg[ff[i]]);
        g[ff[i],kg[ff[i]]]:=ss[i];
      end;
      found:=False;
      rec(need,cnt);
      if ll = rr then break;
      if found then ll:=mid
      else rr:=mid-1;
    end;
  end;
  for i:=1 to k-1 do write(res[i],' ');
  writeln(res[k]);
end.