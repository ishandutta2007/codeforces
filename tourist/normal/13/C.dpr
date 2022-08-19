{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
var
  f,g: array [0..5010] of int64;
  a,b: array [0..5010] of longint;
  j,q,n,i,m: longint;
  inf,min,ans: int64;

procedure Sort(l,r:longint);
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
      tmp:=b[i]; b[i]:=b[j]; b[j]:=tmp;
      inc(i); dec(j);
    end;
  until i > j;
  if l < j then Sort(l,j);
  if i < r then Sort(i,r);
end;

begin
  randseed:=8753;
  inf:=round(1e18);
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do b[i]:=a[i];
  Sort(1,n);
  m:=1;
  for i:=2 to n do
    if b[i] <> b[m] then
    begin
      inc(m);
      b[m]:=b[i];
    end;
  for i:=1 to m do f[i]:=inf;
  f[1]:=0;
  for i:=1 to n do
  begin
    min:=inf;
    for j:=1 to m do
    begin
      if f[j] < min then min:=f[j];
      if b[j] < a[i] then q:=a[i]-b[j]
      else q:=b[j]-a[i];
      g[j]:=min+q;
    end;
    for j:=1 to m do f[j]:=g[j];
  end;
  ans:=inf;
  for j:=1 to m do
    if f[j] < ans then ans:=f[j];
  writeln(ans);
  close(input);
  close(output);
end.