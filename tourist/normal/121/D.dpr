{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
const inf = round(2e18);
var
  n,i,j,e,ans: longint;
  cur,tmp,min,sum,k: int64;
  s,f: array [0..100010] of int64;
  right,left,x: array [0..1111111] of int64;

procedure Sort(l,r:longint);
var
  i,j: longint;
  x,tmp: int64;
begin
  i:=l; j:=r;
  x:=s[l+random(r-l+1)];
  repeat
    while s[i] < x do inc(i);
    while x < s[j] do dec(j);
    if i <= j then
    begin
      tmp:=s[i]; s[i]:=s[j]; s[j]:=tmp;
      tmp:=f[i]; f[i]:=f[j]; f[j]:=tmp;
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
  min:=inf;
  for i:=1 to n do
  begin
    read(s[i],f[i]);
    if f[i]-s[i]+1 < min then min:=f[i]-s[i]+1;
  end;
  Sort(1,n);
  i:=1; e:=2;
  x[0]:=0;
  x[1]:=4;
  x[2]:=7;
  while i <= e do
  begin
    if x[i]*10+4 <= inf then
    begin
      inc(e);
      x[e]:=x[i]*10+4;
    end;
    if x[i]*10+7 <= inf then
    begin
      inc(e);
      x[e]:=x[i]*10+7;
    end;
    inc(i);
  end;
  x[e+1]:=inf;
  j:=n; sum:=0;
  for i:=e downto 1 do
  begin
    while (j > 0) and (s[j] > x[i]) do
    begin
      sum:=sum+s[j]-x[i];
      if sum > inf then sum:=inf;
      dec(j);
    end;
    right[i]:=sum;
    if 1.0*(n-j)*(x[i]-x[i-1]) > 2e18 then sum:=inf else
    begin
      sum:=sum+int64(n-j)*(x[i]-x[i-1]);
      if sum > inf then sum:=inf;
    end;
  end;
  for i:=1 to n do
  begin
    tmp:=s[i]; s[i]:=f[i]; f[i]:=tmp;
  end;
  Sort(1,n);
  j:=1; sum:=0;
  for i:=1 to e do
  begin
    while (j <= n) and (s[j] < x[i]) do
    begin
      sum:=sum+x[i]-s[j];
      if sum > inf then sum:=inf;
      inc(j);
    end;
    left[i]:=sum;
    if 1.0*(j-1)*(x[i+1]-x[i]) > 2e18 then sum:=inf else
    begin
      sum:=sum+int64(j-1)*(x[i+1]-x[i]);
      if sum > inf then sum:=inf;
    end;
  end;
  j:=0; ans:=0;
  for i:=1 to e do
  begin
    if j < i-1 then j:=i-1;
    while j < e do
    begin
      if x[j+1]-x[i]+1 > min then break;
      cur:=right[i]+left[j+1];
      if cur <= k then inc(j)
      else break;
    end;
    if j-i+1 > ans then ans:=j-i+1;
  end;
  writeln(ans);
  close(input);
  close(output);
end.