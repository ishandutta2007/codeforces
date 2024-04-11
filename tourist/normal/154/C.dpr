{$R-,S-,Q-,I-,O+}
{$M 30000000}
var
  pw,h: array [0..1000010] of int64;
  ss,ff: array [0..3000010] of longint;
  pv,r,j,n,m,i: longint;
  hh,ans: int64;

procedure SortE(l,r:longint);
var
  i,j,pp,x,xx,tmp: longint;
begin
  i:=l; j:=r;
  pp:=l+random(r-l+1);
  x:=ss[pp]; xx:=ff[pp];
  repeat
    while (ss[i] < x) or (ss[i] = x) and (ff[i] < xx) do inc(i);
    while (x < ss[j]) or (x = ss[j]) and (xx < ff[j]) do dec(j);
    if i <= j then
    begin
      tmp:=ss[i]; ss[i]:=ss[j]; ss[j]:=tmp;
      tmp:=ff[i]; ff[i]:=ff[j]; ff[j]:=tmp;
      inc(i); dec(j);
    end;
  until i > j;
  if l < j then SortE(l,j);
  if i < r then SortE(i,r);
end;

procedure SortH(l,r:longint);
var
  i,j: longint;
  x,tmp: int64;
begin
  i:=l; j:=r;
  x:=h[l+random(r-l+1)];
  repeat
    while h[i] < x do inc(i);
    while x < h[j] do dec(j);
    if i <= j then
    begin
      tmp:=h[i]; h[i]:=h[j]; h[j]:=tmp;
      inc(i); dec(j);
    end;
  until i > j;
  if l < j then SortH(l,j);
  if i < r then SortH(i,r);
end;

begin
  randomize;
  read(n,m);
  pw[0]:=1;
  for i:=1 to n do pw[i]:=pw[i-1]*98124001;
  for i:=1 to m do
  begin
    read(ss[i],ff[i]);
    ss[i+m]:=ff[i];
    ff[i+m]:=ss[i];
  end;
  m:=m+m;
  ans:=0;
  for r:=0 to 1 do
  begin
    SortE(1,m);
    j:=1;
    for i:=1 to n do
    begin
      hh:=0; pv:=0;
      while (j <= m) and (ss[j] = i) do
      begin
        hh:=hh*pw[ff[j]-pv];
        pv:=ff[j];
        hh:=hh+239;
        inc(j);
      end;
      hh:=hh*pw[n-pv];
      h[i]:=hh;
    end;
    SortH(1,n);
    i:=1;
    while i <= n do
    begin
      j:=i;
      while (j <= n) and (h[i] = h[j]) do inc(j);
      ans:=ans+int64(j-i)*(j-i-1);
      i:=j;
    end;
    if r = 0 then
      for i:=1 to n do
      begin
        inc(m);
        ss[m]:=i;
        ff[m]:=i;
      end;
  end;
  writeln(ans div 2);
end.