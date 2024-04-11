{$R-,S-,Q-,I-,O+}
var
  a: array [0..6] of longint;
  cnt,pr: array [0..10010] of longint;
  u: array [0..10010,0..6] of longint;
  ok: boolean;
  s: string;
  n,j,p,qq,tt,ans,kp,i: longint;

procedure rec(v:longint);
var
  i,lg,rg,ll,rr,mid,j: longint;
  b: array [0..6] of longint;
begin
  if (v = n+1) or (n = 5) and (v = 5) then
  begin
    if v = n+1 then inc(ans)
    else inc(ans,cnt[a[5]]);
    exit;
  end;
  lg:=a[v]; rg:=lg+1;
  for i:=v to n do lg:=lg*10;
  for i:=v to n do rg:=rg*10;
  dec(rg);
  ll:=1; rr:=kp;
  while ll < rr do
  begin
    mid:=(ll+rr) shr 1;
    if pr[mid] < lg then ll:=mid+1
    else rr:=mid;
  end;
  while (ll <= kp) and (pr[ll] <= rg) do
  begin
    for j:=v to n do
    begin
      b[j]:=a[j];
      a[j]:=a[j]*10+u[ll,j+5-n];
    end;
    rec(v+1);
    for j:=v to n do a[j]:=b[j];
    inc(ll);
  end;
end;

begin
  fillchar(cnt,sizeof(cnt),0);
  kp:=0;
  for i:=2 to 100000 do
  begin
    ok:=True;
    for j:=2 to i-1 do
      if j*j > i then break else
      if i mod j = 0 then
      begin
        ok:=False;
        break;
      end;
    if ok then
    begin
      inc(kp);
      pr[kp]:=i;
      j:=i;
      for qq:=5 downto 1 do
      begin
        u[kp,qq]:=j mod 10;
        j:=j div 10;
      end;
      inc(cnt[i div 10]);
    end;
  end;
  read(tt);
  for qq:=1 to tt do
  begin
    read(p);
    str(p,s);
    n:=length(s);
    for i:=2 to n do a[i]:=Ord(s[i])-48;
    ans:=0;
    rec(2);
    writeln(ans);
  end;
end.