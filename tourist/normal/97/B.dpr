{$R-,S-,Q-,I-,O+}
{$M 50000000}
var
  xx,yy,x,y,a: array [0..200010] of longint;
  n,m,i: longint;

procedure SortX(l,r:longint);
var
  i,j,xx,tmp: longint;
begin
  i:=l; j:=r;
  xx:=x[l+random(r-l+1)];
  repeat
    while x[i] < xx do inc(i);
    while xx < x[j] do dec(j);
    if i <= j then
    begin
      tmp:=x[i]; x[i]:=x[j]; x[j]:=tmp;
      tmp:=y[i]; y[i]:=y[j]; y[j]:=tmp;
      inc(i); dec(j);
    end;
  until i > j;
  if l < j then SortX(l,j);
  if i < r then SortX(i,r);
end;

procedure SortA(l,r:longint);
var
  i,j,xx,tmp: longint;
begin
  i:=l; j:=r;
  xx:=a[l+random(r-l+1)];
  repeat
    while a[i] < xx do inc(i);
    while xx < a[j] do dec(j);
    if i <= j then
    begin
      tmp:=a[i]; a[i]:=a[j]; a[j]:=tmp;
      inc(i); dec(j);
    end;
  until i > j;
  if l < j then SortA(l,j);
  if i < r then SortA(i,r);
end;

procedure go(l,r:longint);
var
  mid,k,i: longint;
begin
  mid:=(l+r) shr 1;
  k:=0;
  for i:=l to r do
  begin
    inc(k);
    a[k]:=y[i];
  end;
  SortA(1,k);
  for i:=1 to k do
    if (i = 1) or (a[i] <> a[i-1]) then
    begin
      inc(m);
      xx[m]:=x[mid];
      yy[m]:=a[i];
    end;
  i:=mid-1;
  while (i >= l) and (x[i] = x[mid]) do dec(i);
  if i >= l then go(l,i);
  i:=mid+1;
  while (i <= r) and (x[i] = x[mid]) do inc(i);
  if i <= r then go(i,r);
end;

begin
  randseed:=912834;
  read(n);
  for i:=1 to n do read(x[i],y[i]);
  SortX(1,n);
  m:=0;
  go(1,n);
  writeln(m);
  for i:=1 to m do writeln(xx[i],' ',yy[i]);
end.