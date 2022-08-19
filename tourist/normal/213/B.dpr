{$R-,S-,Q-,I-,O+}
const md = round(1e9+7);
var
  n,i,j,k,ans: longint;
  fact,fi,a: array [0..222] of longint;
  f: array [0..222,0..222] of longint;

function inv(a:longint):longint;
var
  x,step: longint;
begin
  x:=1; step:=1 shl 30;
  while step > 0 do
  begin
    x:=int64(x)*x mod md;
    if step and (md-2) <> 0 then x:=int64(x)*a mod md;
    step:=step shr 1;
  end;
  inv:=x;
end;

begin
  read(n);
  for i:=0 to 9 do read(a[i]);
  fact[0]:=1;
  for i:=1 to 200 do fact[i]:=int64(fact[i-1])*i mod md;
  for i:=0 to 200 do fi[i]:=inv(fact[i]);
  fillchar(f,sizeof(f),0);
  f[9,0]:=1;
  for i:=9 downto 1 do
    for j:=0 to n do
      if f[i,j] > 0 then
        for k:=a[i] to n-j do
          f[i-1,j+k]:=(f[i-1,j+k]+int64(f[i,j])*fi[k]) mod md;
  ans:=0;
  for j:=1 to n do
    if f[0,j] > 0 then
      for k:=a[0] to n-j do
      begin
        ans:=(ans+(int64(f[0,j])*fi[k] mod md)*fact[j+k]) mod md;
        if k > 0 then ans:=(ans-(int64(f[0,j])*fi[k-1] mod md)*fact[j+k-1]) mod md;
        if ans < 0 then ans:=(ans+md) mod md;
      end;
  writeln(ans);
end.