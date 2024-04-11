{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
var
  e,ll,mid,rr,n,i,m,x,y,j,q,kt: longint;
  cur,ans: int64;
  ok: boolean;
  lucky: array [0..100010] of boolean;
  kg,pr,ne,b,id,c,t,w,u,a: array [0..100010] of longint;
  g,r,left,right: array [0..1010,0..1010] of longint;

procedure Sort(l,r:longint);
var
  i,j,x,tmp: longint;
begin
  i:=l; j:=r;
  x:=u[l+random(r-l+1)];
  repeat
    while u[i] < x do inc(i);
    while x < u[j] do dec(j);
    if i <= j then
    begin
      tmp:=u[i]; u[i]:=u[j]; u[j]:=tmp;
      tmp:=t[i]; t[i]:=t[j]; t[j]:=tmp;
      inc(i); dec(j);
    end;
  until i > j;
  if l < j then Sort(l,j);
  if i < r then Sort(i,r);
end;

begin
  randomize;
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  m:=0;
  for i:=1 to n do
  begin
    read(a[i]);
    x:=a[i];
    ok:=True;
    while x > 0 do
    begin
      y:=x mod 10;
      if not ((y = 4) or (y = 7)) then
      begin
        ok:=False;
        break;
      end;
      x:=x div 10;
    end;
    lucky[i]:=ok;
    if ok then
    begin
      inc(m);
      b[m]:=i;
      id[i]:=m;
    end;
  end;
  q:=0;
  for i:=1 to m do
  begin
    c[i]:=0;
    for j:=1 to i-1 do
      if a[b[i]] = a[b[j]] then
      begin
        c[i]:=c[j];
        break;
      end;
    if c[i] = 0 then
    begin
      inc(q);
      c[i]:=q;
    end;
  end;
  for i:=1 to m do
  begin
    for j:=1 to q do w[i]:=0;
    for j:=1 to i do w[c[j]]:=j;
    kt:=0;
    for j:=i+1 to m do
      if w[c[j]] > 0 then
      begin
        inc(kt);
        t[kt]:=j;
      end;
    kg[i]:=kt;
    if kt = 0 then continue;
    t[0]:=i; t[kt+1]:=m+1;
    for j:=1 to kt do
    begin
      pr[t[j]]:=t[j-1];
      ne[t[j]]:=t[j+1];
    end;
    for j:=1 to kt do u[j]:=w[c[t[j]]];
    Sort(1,kt);
    for j:=1 to kt do
    begin
      g[i,kt-j+1]:=t[j];
      r[i,kt-j+1]:=u[j];
      left[i,kt-j+1]:=pr[t[j]];
      right[i,kt-j+1]:=ne[t[j]];
      pr[ne[t[j]]]:=pr[t[j]];
      ne[pr[t[j]]]:=ne[t[j]];
    end;
  end;
  b[0]:=0; b[m+1]:=n+1;
  e:=0; ans:=0;
  for i:=1 to n do
  begin
    if lucky[i] then inc(e);
    cur:=int64(n-i)*(n-i+1) shr 1;
    ans:=ans+cur*(i-b[e]);
    x:=1;
    for j:=e downto 1 do
    begin
      while (x <= kg[e]) and (r[e,x] = j) do
      begin
        mid:=b[g[e,x]];
        ll:=b[left[e,x]];
        rr:=b[right[e,x]];
        if ll < i then ll:=i;
        cur:=cur-int64(mid-ll)*(rr-mid);
        inc(x);
      end;
      ans:=ans+cur*(b[j]-b[j-1]);
    end;
  end;
  writeln(ans);
//  close(input);
//  close(output);
end.