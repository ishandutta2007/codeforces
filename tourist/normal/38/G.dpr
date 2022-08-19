{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
const inf = round(1e9);
var
  t,ll,rr,mid,x,n,i: longint;
  ans,s,pz,a,b: array [0..100010] of longint;
  max,add: array [0..555555] of longint;

procedure modify(x,l,r,ll,rr,v:longint);
begin
  if (ll > r) or (l > rr) then exit;
  if (l >= ll) and (r <= rr) then inc(add[x],v) else
  begin
    if add[x] <> 0 then
    begin
      inc(add[x+x],add[x]);
      inc(add[x+x+1],add[x]);
      add[x]:=0;
    end;
    modify(x+x,l,(l+r) shr 1,ll,rr,v);
    modify(x+x+1,(l+r) shr 1+1,r,ll,rr,v);
    max[x]:=max[x+x+1]+add[x+x+1];
    if max[x+x]+add[x+x] > max[x] then max[x]:=max[x+x]+add[x+x];
  end;
end;

function findmax(x,l,r,ll,rr:longint):longint;
var
  res,t: longint;
begin
  if (ll > r) or (l > rr) then
  begin
    findmax:=-inf;
    exit;
  end;
  if (l >= ll) and (r <= rr) then findmax:=max[x]+add[x] else
  begin
    if add[x] <> 0 then
    begin
      inc(add[x+x],add[x]);
      inc(add[x+x+1],add[x]);
      add[x]:=0;
    end;
    res:=findmax(x+x,l,(l+r) shr 1,ll,rr);
    t:=findmax(x+x+1,(l+r) shr 1+1,r,ll,rr);
    if t > res then res:=t;
    findmax:=res;
  end;
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  fillchar(max,sizeof(max),0);
  fillchar(add,sizeof(add),0);
  add[1]:=-inf;
  for i:=1 to n do
  begin
    read(a[i],b[i]);
    pz[i]:=i-b[i];
    if pz[i] < 1 then pz[i]:=1;
    if a[i] < n then
    begin
      t:=findmax(1,1,n,a[i]+1,n)+1;
      if t > pz[i] then pz[i]:=t;
    end;
    t:=findmax(1,1,n,a[i],a[i]);
    modify(1,1,n,a[i],a[i],pz[i]-t);
    if a[i] > 1 then modify(1,1,n,1,a[i]-1,1);
  end;
  fillchar(s,sizeof(s),0);
  fillchar(ans,sizeof(ans),0);
  for i:=1 to n do
  begin
    inc(s[i]);
    x:=(i or (i-1))+1;
    if x <= n then inc(s[x],s[i]);
  end;
  for i:=n downto 1 do
  begin
    ll:=1; rr:=n;
    while ll < rr do
    begin
      mid:=(ll+rr) shr 1;
      t:=0; x:=mid;
      while x > 0 do
      begin
        inc(t,s[x]);
        x:=x and (x-1);
      end;
      if t >= pz[i] then rr:=mid
      else ll:=mid+1;
    end;
    ans[ll]:=i;
    x:=ll;
    while x <= n do
    begin
      dec(s[x]);
      x:=(x or (x-1))+1;
    end;
  end;
  for i:=1 to n-1 do write(ans[i],' ');
  writeln(ans[n]);
  close(input);
  close(output);
end.