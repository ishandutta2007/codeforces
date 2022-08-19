{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
const md = round(1e9+7);
var
  cur,n,k,i,j,x,m,k1,ans,step,y: longint;
  f: array [0..2010,0..2010] of longint;
  fact,inv,b,a: array [0..100010] of longint;
  ok: boolean;

procedure Sort(l,r:longint);
var
  i,j,x,tmp: longint;
begin
  i:=l; j:=r;
  x:=a[l+random(r-l+1)];
  repeat
    while a[i] < x do inc(i);
    while x < a[j] do dec(j);
    if i <= j then
    begin
      tmp:=a[i]; a[i]:=a[j]; a[j]:=tmp;
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
  read(n,k);
  for i:=1 to n do read(a[i]);
  Sort(1,n);
  k1:=0; m:=0;
  i:=1;
  while i <= n do
  begin
    j:=i;
    while (j <= n) and (a[i] = a[j]) do inc(j);
    x:=a[i]; ok:=True;
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
    if ok and (j-i > 1) then
    begin
      inc(m);
      b[m]:=j-i;
    end
    else inc(k1,j-i);
    i:=j;
  end;
  fillchar(f,sizeof(f),0);
  f[0,0]:=1;
  for i:=1 to m do
    for j:=0 to i do
    begin
      f[i,j]:=f[i-1,j];
      if j > 0 then f[i,j]:=(f[i,j]+int64(f[i-1,j-1])*b[i]) mod md;
    end;
  fact[0]:=1;
  for i:=1 to n do fact[i]:=int64(fact[i-1])*i mod md;
  for i:=0 to n do
  begin
    x:=1; step:=1 shl 30;
    while step > 0 do
    begin
      x:=int64(x)*x mod md;
      if step and (md-2) <> 0 then x:=int64(x)*fact[i] mod md;
      step:=step shr 1;
    end;
    inv[i]:=x;
  end;
  ans:=0;
  for j:=0 to m do
    if (j <= k) and (k-j <= k1) then
    begin
      cur:=int64(f[m,j])*fact[k1] mod md;
      cur:=int64(cur)*inv[k-j] mod md;
      ans:=(ans+int64(cur)*inv[k1-(k-j)]) mod md;
    end;
  writeln(ans);
//  close(input);
//  close(output);
end.