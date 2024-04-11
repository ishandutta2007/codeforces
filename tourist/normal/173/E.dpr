{$R-,S-,Q-,I-,O+}
var
  lo,hi,ke,n,k,tt,qq,i,ii,jj,kk,ll,rr,mid,u: longint;
  ma,ml,mr,e,pe,x,y,z,ans,pz,s,size,a,b,num: array [0..400010] of longint;

procedure SortB(l,r:longint);
var
  i,j,x,tmp: longint;
begin
  i:=l; j:=r;
  x:=b[l+random(r-l+1)];
  repeat
    while b[i] < x do inc(i);
    while x < b[j] do dec(j);
    if i <= j then
    begin
      tmp:=a[i]; a[i]:=a[j]; a[j]:=tmp;
      tmp:=b[i]; b[i]:=b[j]; b[j]:=tmp;
      tmp:=num[i]; num[i]:=num[j]; num[j]:=tmp;
      inc(i); dec(j);
    end;
  until i > j;
  if l < j then SortB(l,j);
  if i < r then SortB(i,r);
end;

procedure SortA(l,r:longint);
var
  i,j,x,tmp: longint;
begin
  i:=l; j:=r;
  x:=num[l+random(r-l+1)];
  repeat
    while a[num[i]] < a[x] do inc(i);
    while a[x] < a[num[j]] do dec(j);
    if i <= j then
    begin
      tmp:=num[i]; num[i]:=num[j]; num[j]:=tmp;
      inc(i); dec(j);
    end;
  until i > j;
  if l < j then SortA(l,j);
  if i < r then SortA(i,r);
end;

procedure SortE(l,r:longint);
var
  i,j,pp,x,xx,tmp: longint;
begin
  i:=l; j:=r;
  pp:=l+random(r-l+1);
  x:=e[pp]; xx:=pe[pp];
  repeat
    while (e[i] > x) or (e[i] = x) and (pe[i] > xx) do inc(i);
    while (x > e[j]) or (x = e[j]) and (xx > pe[j]) do dec(j);
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

procedure modify(x,v:longint);
begin
  while x <= n do
  begin
    inc(s[x],v);
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
    inc(v,s[x]);
    x:=x and (x-1);
  end;
  findsum:=v;
end;

procedure modify2(q,v:longint);
var
  x: longint;
begin
  if v > ma[q] then ma[q]:=v;
  x:=q;
  while x <= n do
  begin
    if v > ml[x] then ml[x]:=v;
    x:=(x or (x-1))+1;
  end;
  x:=q;
  while x > 0 do
  begin
    if v > mr[x] then mr[x]:=v;
    x:=x and (x-1);
  end;
end;

function findmax(ll,rr:longint):longint;
var
  x,mx: longint;
begin
  mx:=0; x:=ll;
  while (x or (x-1))+1 <= rr do
  begin
    if mr[x] > mx then mx:=mr[x];
    x:=(x or (x-1))+1;
  end;
  if ma[x] > mx then mx:=ma[x];
  x:=rr;
  while (x and (x-1)) >= ll do
  begin
    if ml[x] > mx then mx:=ml[x];
    x:=x and (x-1);
  end;
  findmax:=mx;
end;

begin
  randomize;
  read(n,k);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do read(b[i]);
  for i:=1 to n do num[i]:=i;
  SortB(1,n);
  for i:=1 to n do pz[num[i]]:=i;
  for i:=1 to n do num[i]:=i;
  SortA(1,n);
  fillchar(s,sizeof(s),0);
  ii:=1;
  while ii <= n do
  begin
    jj:=ii;
    while (jj <= n) and (a[num[ii]] = a[num[jj]]) do inc(jj);
    for kk:=ii to jj-1 do modify(num[kk],1);
    for kk:=ii to jj-1 do
    begin
      i:=num[kk];
      ll:=1; rr:=i;
      while ll < rr do
      begin
        mid:=(ll+rr) shr 1;
        if b[mid] < b[i]-k then ll:=mid+1
        else rr:=mid;
      end;
      u:=findsum(ll-1);
      ll:=i; rr:=n;
      while ll < rr do
      begin
        mid:=(ll+rr+1) shr 1;
        if b[mid] > b[i]+k then rr:=mid-1
        else ll:=mid;
      end;
      u:=findsum(ll)-u;
      size[i]:=u;
    end;
    ii:=jj;
  end;
  read(tt);
  for qq:=1 to tt do
  begin
    read(x[qq],y[qq]);
    x[qq]:=pz[x[qq]];
    y[qq]:=pz[y[qq]];
    if x[qq] > y[qq] then begin ii:=x[qq]; x[qq]:=y[qq]; y[qq]:=ii; end;
    z[qq]:=a[x[qq]];
    if a[y[qq]] > z[qq] then z[qq]:=a[y[qq]];
    ans[qq]:=0;
  end;
  ke:=0;
  for i:=1 to n do
  begin
    inc(ke);
    e[ke]:=a[i];
    pe[ke]:=i;
  end;
  for i:=1 to tt do
  begin
    inc(ke);
    e[ke]:=z[i];
    pe[ke]:=-i;
  end;
  SortE(1,ke);
  fillchar(ma,sizeof(ma),0);
  fillchar(ml,sizeof(ml),0);
  fillchar(mr,sizeof(mr),0);
  for i:=1 to ke do
    if pe[i] > 0 then modify2(pe[i],size[pe[i]]) else
    begin
      ii:=-pe[i];
      ll:=1; rr:=y[ii];
      while ll < rr do
      begin
        mid:=(ll+rr) shr 1;
        if b[mid] < b[y[ii]]-k then ll:=mid+1
        else rr:=mid;
      end;
      lo:=ll;
      ll:=x[ii]; rr:=n;
      while ll < rr do
      begin
        mid:=(ll+rr+1) shr 1;
        if b[mid] > b[x[ii]]+k then rr:=mid-1
        else ll:=mid;
      end;
      hi:=ll;
      if lo <= hi then ans[ii]:=findmax(lo,hi);
    end;
  for i:=1 to tt do
    if ans[i] < 2 then writeln(-1)
    else writeln(ans[i]);
end.