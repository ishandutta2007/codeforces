{$R-,S-,Q-,I-,O+}
const md = round(1e9+7);
var
  s: array [-1..1000010] of char;
  f,fs,g,gs,w: array [-1..1000010] of longint;
  a: array [-1..1000010,0..4] of longint;
  q,n,k,i,lg,rg,ans: longint;
begin
  readln(n,k);
  for i:=1 to n do read(s[i]);
  fs[-1]:=0;
  f[0]:=1; fs[0]:=1;
  q:=0;
  for i:=1 to n do
  begin
    lg:=i-k;
    if lg < q then lg:=q;
    if s[i] <> 'B' then
    begin
      f[i]:=fs[i-1]-fs[lg-1]+md;
      if f[i] >= md then dec(f[i],md);
    end
    else f[i]:=0;
    fs[i]:=fs[i-1]+f[i];
    if fs[i] >= md then dec(fs[i],md);
    if s[i] = 'W' then q:=i;
  end;
  g[n+2]:=0;
  g[n+1]:=1; gs[n+1]:=1;
  q:=n+1;
  for i:=n downto 1 do
  begin
    rg:=i+k;
    if rg > q then rg:=q;
    if s[i] <> 'W' then
    begin
      g[i]:=gs[i+1]-gs[rg+1]+md;
      if g[i] >= md then dec(g[i],md);
    end
    else g[i]:=0;
    gs[i]:=gs[i+1]+g[i];
    if gs[i] >= md then dec(gs[i],md);
    if s[i] = 'B' then q:=i;
  end;
  a[0,0]:=0; a[0,1]:=0; a[0,2]:=0;
  for i:=1 to n do
  begin
    a[i]:=a[i-1];
    if s[i] = 'X' then inc(a[i,0]) else
    if s[i] = 'W' then inc(a[i,1])
    else inc(a[i,2]);
  end;
  w[n+1]:=0;
  for i:=n downto 1 do
  begin
    w[i]:=w[i+1];
    if s[i] = 'X' then
    begin
      w[i]:=w[i]+w[i];
      if w[i] >= md then dec(w[i],md);
    end;
    if i+k-1 <= n then
      if a[i+k-1,2]-a[i-1,2] = 0 then
      begin
        w[i]:=w[i]+g[i+k];
        if w[i] >= md then dec(w[i],md);
      end;
  end;
  ans:=0;
  for i:=k to n do
    if a[i,1]-a[i-k,1] = 0 then
      ans:=(ans+int64(f[i-k])*w[i+1]) mod md;
  writeln(ans);
end.