{$R-,S-,Q-,I-,O+}
{$M 50000000}
const inf: int64 = round(1e16);
var
  fr,pc,c,np,p,ss,ff,dd,pred,last,pr,h,hh: array [0..400010] of longint;
  min: array [0..400010] of int64;
  was: array [0..400010] of boolean;
  cur,ans: int64;
  xx,yy,kc,kh,n,m,mm,kp,i,j,q,ii: longint;
  d: array [0..400010,0..3] of int64;
  dc,pz: array [0..400010,0..3] of longint;

function findset(x:longint):longint;
begin
  if x <> pr[x] then pr[x]:=findset(pr[x]);
  findset:=pr[x];
end;

procedure up(t:longint);
var
  tmp: longint;
begin
  while (t > 1) and (d[h[t],hh[t]] < d[h[t shr 1],hh[t shr 1]]) do
  begin
    tmp:=h[t]; h[t]:=h[t shr 1]; h[t shr 1]:=tmp;
    tmp:=hh[t]; hh[t]:=hh[t shr 1]; hh[t shr 1]:=tmp;
    pz[h[t],hh[t]]:=t;
    t:=t shr 1;
    pz[h[t],hh[t]]:=t;
  end;
end;

procedure down(t:longint);
var
  w,tmp: longint;
begin
  while True do
  begin
    w:=t shl 1;
    if w > kh then break;
    if w < kh then
      if d[h[w+1],hh[w+1]] < d[h[w],hh[w]] then inc(w);
    if d[h[w],hh[w]] < d[h[t],hh[t]] then
    begin
      tmp:=h[t]; h[t]:=h[w]; h[w]:=tmp;
      tmp:=hh[t]; hh[t]:=hh[w]; hh[w]:=tmp;
      pz[h[t],hh[t]]:=t;
      t:=w;
      pz[h[t],hh[t]]:=t;
    end
    else break;
  end;
end;

begin
  read(n,m);
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
  read(kp);
  for i:=1 to n do np[i]:=0;
  for i:=1 to kp do
  begin
    read(p[i]);
    np[p[i]]:=i;
  end;
  for i:=1 to kp do pr[i]:=i;
  mm:=0; ans:=0;
  while mm <= kp-1 do
  begin
    for i:=1 to kp do was[i]:=False;
    for i:=1 to kp do was[findset(i)]:=True;
    kc:=0;
    for i:=1 to kp do
      if was[i] then
      begin
        inc(kc);
        pc[kc]:=i;
        c[i]:=kc;
      end;
    for i:=1 to kp do
      if not was[i] then c[i]:=c[pr[i]];
    for i:=1 to n do
    begin
      if np[i] > 0 then
      begin
        d[i,1]:=0;
        dc[i,1]:=c[np[i]];
      end else
      begin
        d[i,1]:=inf;
        dc[i,1]:=0;
      end;
      d[i,2]:=inf;
      dc[i,2]:=0;
    end;
    for i:=1 to n do
      for j:=1 to 2 do
      begin
        inc(kh);
        h[kh]:=i;
        hh[kh]:=j;
        pz[i,j]:=kh;
        up(kh);
      end;
    while kh > 1 do
    begin
      i:=h[1]; j:=hh[1];
      if d[i,j] = inf then break;
      pz[i,j]:=0;
      h[1]:=h[kh]; hh[1]:=hh[kh];
      pz[h[1],hh[1]]:=1;
      dec(kh);
      down(1);
      q:=last[i];
      while q > 0 do
      begin
        cur:=d[i,j]+dd[q];
        ii:=ff[q];
        if cur < d[ii,1] then
        begin
          if dc[ii,1] = dc[i,j] then
          begin
            d[ii,1]:=cur;
            up(pz[ii,1]);
          end else
          begin
            d[ii,2]:=d[ii,1];
            dc[ii,2]:=dc[ii,1];
            up(pz[ii,2]);
            d[ii,1]:=cur;
            dc[ii,1]:=dc[i,j];
            up(pz[ii,1]);
          end;
        end else
        if (dc[ii,1] <> dc[i,j]) and (cur < d[ii,2]) then
        begin
          d[ii,2]:=cur;
          dc[ii,2]:=dc[i,j];
          up(pz[ii,2]);
        end;
        q:=pred[q];
      end;
    end;
    if mm = kp-1 then
    begin
      ans:=ans+d[1,1];
      break;
    end;
    for i:=1 to kc do
    begin
      min[i]:=inf;
      fr[i]:=0;
    end;
    for i:=1 to kp do
      if d[p[i],2] < min[c[i]] then
      begin
        min[c[i]]:=d[p[i],2];
        fr[c[i]]:=dc[p[i],2];
      end;
    for i:=1 to kc do
    begin
      xx:=findset(pc[i]);
      yy:=findset(pc[fr[i]]);
      if xx <> yy then
      begin
        inc(mm);
        pr[xx]:=yy;
        ans:=ans+min[i];
      end;
    end;
  end;
  writeln(ans);
end.