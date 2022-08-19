{$R-,S-,Q-,I-,O+}
const inf = round(1e9);
var
  s: array [0..400010] of char;
  wlen,where,ls,sum,ps,lcp,id,pred,t,a,pz,g,ng: array [0..400010] of longint;
  min: array [0..1111111] of longint;
  ans: array [0..400010] of int64;
  d: array [0..20,0..400010] of longint;
  last: array ['a'..'z'] of longint;
  left,right,cur,tot,ll,rr,mid,it,q,n,kk,k,step,i,j,len,nn,kg,nkg: longint;
  ch: char;
  word: array [0..100010] of ansistring;

procedure Sort(l,r:longint);
var
  i,j,x,tmp: longint;
begin
  i:=l; j:=r;
  x:=t[l+random(r-l+1)];
  repeat
    while t[i] < x do inc(i);
    while x < t[j] do dec(j);
    if i <= j then
    begin
      tmp:=t[i]; t[i]:=t[j]; t[j]:=tmp;
      tmp:=a[i]; a[i]:=a[j]; a[j]:=tmp;
      inc(i); dec(j);
    end;
  until i > j;
  if l < j then Sort(l,j);
  if i < r then Sort(i,r);
end;

procedure modify(x,v:longint);
begin
  while x <= nn do
  begin
    inc(sum[x],v);
    x:=(x or (x-1))+1;
  end;
end;

function findsum(x:longint):longint;
var
  v: longint;
begin
  v:=0;
  while x > 0 do
  begin
    v:=v+sum[x];
    x:=x and (x-1);
  end;
  findsum:=v;
end;

procedure build(x,l,r:longint);
begin
  if l = r then min[x]:=lcp[l] else
  begin
    build(x+x,l,(l+r) shr 1);
    build(x+x+1,(l+r) shr 1+1,r);
    min[x]:=min[x+x+1];
    if min[x+x] < min[x] then min[x]:=min[x+x];
  end;
end;

function goleft(x,l,r,p,v:longint):longint;
var
  mid,res: longint;
begin
  mid:=(l+r) shr 1;
  if r <= p then
  begin
    if min[x] >= v then goleft:=0 else
    if l = r then goleft:=l else
    if min[x+x+1] < v then goleft:=goleft(x+x+1,mid+1,r,p,v)
    else goleft:=goleft(x+x,l,mid,p,v);
    exit;
  end;
  if l > p then
  begin
    goleft:=0;
    exit;
  end;
  res:=goleft(x+x+1,mid+1,r,p,v);
  if res = 0 then res:=goleft(x+x,l,mid,p,v);
  goleft:=res;
end;

function goright(x,l,r,p,v:longint):longint;
var
  mid,res: longint;
begin
  mid:=(l+r) shr 1;
  if l >= p then
  begin
    if min[x] >= v then goright:=nn else
    if l = r then goright:=l else
    if min[x+x] < v then goright:=goright(x+x,l,mid,p,v)
    else goright:=goright(x+x+1,mid+1,r,p,v);
    exit;
  end;
  if r < p then
  begin
    goright:=nn;
    exit;
  end;
  res:=goright(x+x,l,mid,p,v);
  if res = nn then res:=goright(x+x+1,mid+1,r,p,v);
  goright:=res;
end;

begin
  randomize;
  readln(n,kk);
  len:=0;
  for i:=1 to n do
  begin
    readln(word[i]);
    wlen[i]:=length(word[i]);
    for j:=1 to wlen[i] do
    begin
      inc(len);
      s[len]:=word[i,j];
      id[len]:=i;
      ps[len]:=j;
    end;
    inc(len);
    s[len]:='$';
    id[len]:=0;
  end;
  if (n = 1) and (wlen[1] = 1) then
  begin
    if kk = 1 then writeln(1)
    else writeln(0);
    halt;
  end;
  fillchar(last,sizeof(last),0);
  for i:=len downto 1 do
    if s[i] <> '$' then
    begin
      pred[i]:=last[s[i]];
      last[s[i]]:=i;
    end;
  kg:=0; i:=0;
  for ch:='a' to 'z' do
  begin
    if last[ch] = 0 then continue;
    inc(kg);
    j:=last[ch];
    while j > 0 do
    begin
      inc(i);
      a[i]:=j;
      g[i]:=kg;
      pz[j]:=i;
      j:=pred[j];
    end;
  end;
  nn:=i;
  step:=1; it:=0;
  while kg < nn do
  begin
    for i:=1 to len do
      if s[i] <> '$' then d[it,i]:=g[pz[i]];
    inc(it);
    nkg:=0; i:=1;
    while i <= nn do
    begin
      j:=i;
      while (j <= nn) and (g[i] = g[j]) do inc(j);
      for k:=i to j-1 do
      begin
        q:=a[k]+step;
        if q > len then t[k]:=-inf else
        if s[q] = '$' then t[k]:=-inf+q
        else t[k]:=g[pz[q]];
      end;
      Sort(i,j-1);
      for k:=i to j-1 do
      begin
        if (k = i) or (t[k] <> t[k-1]) then inc(nkg);
        ng[k]:=nkg;
      end;
      i:=j;
    end;
    kg:=nkg;
    for i:=1 to nn do pz[a[i]]:=i;
    for i:=1 to nn do g[i]:=ng[i];
    step:=step shl 1;
  end;
  for i:=1 to nn-1 do
  begin
    lcp[i]:=0;
    for j:=it-1 downto 0 do
      if d[j,a[i]+lcp[i]] = d[j,a[i+1]+lcp[i]] then
      begin
        inc(lcp[i],1 shl j);
        if s[a[i]+lcp[i]] = '$' then break;
      end;
  end;
  fillchar(ls,sizeof(ls),0);
  fillchar(sum,sizeof(sum),0);
  for i:=1 to nn do
  begin
    j:=id[a[i]];
    modify(i,1);
    if ls[j] > 0 then modify(ls[j],-1);
    ls[j]:=i;
    tot:=findsum(i);
    ll:=0; rr:=i;
    while ll < rr do
    begin
      mid:=(ll+rr+1) shr 1;
      cur:=tot-findsum(mid-1);
      if cur >= kk then ll:=mid
      else rr:=mid-1;
    end;
    where[i]:=ll;
  end;
  for i:=1 to n do ans[i]:=0;
  build(1,1,nn-1);
  for i:=1 to nn do
  begin
    ll:=0; rr:=wlen[id[a[i]]]-ps[a[i]]+1;
    while ll < rr do
    begin
      mid:=(ll+rr+1) shr 1;
      left:=goleft(1,1,nn-1,i-1,mid)+1;
      right:=goright(1,1,nn-1,i,mid);
      if where[right] >= left then ll:=mid
      else rr:=mid-1;
    end;
    ans[id[a[i]]]:=ans[id[a[i]]]+ll;
  end;
  for i:=1 to n-1 do write(ans[i],' ');
  writeln(ans[n]);
end.