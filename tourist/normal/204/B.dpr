{$R-,S-,Q-,I-,O+}
var
  a,b: array [0..500010] of longint;
  n,m,i,j,q,w,min,x,y,need,k: longint;

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
      tmp:=b[i]; b[i]:=b[j]; b[j]:=tmp;
      inc(i); dec(j);
    end;
  until i > j;
  if l < j then Sort(l,j);
  if i < r then Sort(i,r);
end;

begin
  randomize;
  read(n);
  m:=0;
  for i:=1 to n do
  begin
    read(q,w);
    inc(m);
    a[m]:=q;
    b[m]:=1;
    if q <> w then
    begin
      inc(m);
      a[m]:=w;
      b[m]:=2;
    end;
  end;
  Sort(1,m);
  min:=maxlongint;
  i:=1;
  while i <= m do
  begin
    j:=i;
    while (j <= m) and (a[j] = a[i]) do inc(j);
    x:=0; y:=0;
    for k:=i to j-1 do
      if b[k] = 1 then inc(x)
      else inc(y);
    if x+y >= (n+1) shr 1 then
    begin
      need:=((n+1) shr 1)-x;
      if need < 0 then need:=0;
      if need < min then min:=need;
    end;
    i:=j;
  end;
  if min = maxlongint then writeln(-1)
  else writeln(min);
end.