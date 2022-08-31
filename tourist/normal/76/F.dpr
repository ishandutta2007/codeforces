{$R-,S-,Q-,I-,O+}
var
  t,n,i,v,ans1,ans2,x: longint;
  r,a,b,c,d,f,mx,xx,tt: array [0..100010] of longint;

procedure Sort1(l,r:longint);
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
      tmp:=c[i]; c[i]:=c[j]; c[j]:=tmp;
      inc(i); dec(j);
    end;
  until i > j;
  if l < j then Sort1(l,j);
  if i < r then Sort1(i,r);
end;

procedure Sort2(l,r:longint);
var
  i,j,pp,x,xx,tmp: longint;
begin
  i:=l; j:=r;
  pp:=l+random(r-l+1);
  x:=a[pp]; xx:=d[pp];
  repeat
    while (a[i] < x) or (a[i] = x) and (d[i] < xx) do inc(i);
    while (x < a[j]) or (x = a[j]) and (xx < d[j]) do dec(j);
    if i <= j then
    begin
      tmp:=a[i]; a[i]:=a[j]; a[j]:=tmp;
      tmp:=d[i]; d[i]:=d[j]; d[j]:=tmp;
      inc(i); dec(j);
    end;
  until i > j;
  if l < j then Sort2(l,j);
  if i < r then Sort2(i,r);
end;

begin
  randseed:=8753;
  read(n);
  for i:=1 to n do read(xx[i],tt[i]);
  read(v);
  for i:=1 to n do
  begin
    a[i]:=xx[i]+v*tt[i];
    b[i]:=-xx[i]+v*tt[i];
    c[i]:=i;
  end;
  Sort1(1,n);
  t:=0;
  for i:=1 to n do
  begin
    if (i = 1) or (b[i] <> b[i-1]) then
    begin
      inc(t);
      r[t]:=b[i];
    end;
    d[c[i]]:=t;
  end;
  Sort2(1,n);
  ans1:=0; ans2:=0;
  fillchar(mx,sizeof(mx),0);
  for i:=1 to n do
  begin
    f[i]:=1;
    x:=d[i];
    while x > 0 do
    begin
      if mx[x]+1 > f[i] then f[i]:=mx[x]+1;
      x:=x and (x-1);
    end;
    if (a[i] < 0) or (r[d[i]] < 0) then f[i]:=0;
    x:=d[i];
    while x <= t do
    begin
      if f[i] > mx[x] then mx[x]:=f[i];
      x:=(x or (x-1))+1;
    end;
    if f[i] > ans1 then ans1:=f[i];
  end;
  fillchar(mx,sizeof(mx),0);
  for i:=1 to n do
  begin
    f[i]:=1;
    x:=d[i];
    while x > 0 do
    begin
      if mx[x]+1 > f[i] then f[i]:=mx[x]+1;
      x:=x and (x-1);
    end;
    x:=d[i];
    while x <= t do
    begin
      if f[i] > mx[x] then mx[x]:=f[i];
      x:=(x or (x-1))+1;
    end;
    if f[i] > ans2 then ans2:=f[i];
  end;
  writeln(ans1,' ',ans2);
end.