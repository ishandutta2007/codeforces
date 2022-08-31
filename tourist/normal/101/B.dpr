{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
const md = round(1e9+7);
var
  a,b,e,pe,f,s: array [0..400010] of longint;
  ans,t,n,q,ke,i: longint;

procedure SortE(l,r:longint);
var
  i,j,x,tmp: longint;
begin
  i:=l; j:=r;
  x:=e[l+random(r-l+1)];
  repeat
    while e[i] < x do inc(i);
    while x < e[j] do dec(j);
    if i <= j then
    begin
      tmp:=e[i]; e[i]:=e[j]; e[j]:=tmp;
      tmp:=pe[i]; pe[i]:=pe[j]; pe[j]:=tmp;
      inc(i); dec(j);
    end;
  until i > j;
  if l < j then SortE(l,j);
  if i < r then SortE(i,r);
end;

procedure SortA(l,r:longint);
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
      tmp:=a[i]; a[i]:=a[j]; a[j]:=tmp;
      tmp:=b[i]; b[i]:=b[j]; b[j]:=tmp;
      inc(i); dec(j);
    end;
  until i > j;
  if l < j then SortA(l,j);
  if i < r then SortA(i,r);
end;

function findsum(x:longint):longint;
var
  t: longint;
begin
  t:=0;
  while x > 0 do
  begin
    t:=(t+s[x]) mod md;
    x:=x and (x-1);
  end;
  findsum:=t;
end;

procedure modify(x,v:longint);
begin
  while x <= t+1 do
  begin
    s[x]:=(s[x]+v) mod md;
    x:=(x or (x-1))+1;
  end;
end;

begin
  randseed:=8753;
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(q,n);
  ke:=2;
  e[1]:=0; pe[1]:=0;
  e[2]:=q; pe[2]:=0;
  for i:=1 to n do
  begin
    read(a[i],b[i]);
    inc(ke);
    e[ke]:=a[i];
    pe[ke]:=i;
    inc(ke);
    e[ke]:=b[i];
    pe[ke]:=-i;
  end;
  SortE(1,ke);
  t:=0;
  for i:=1 to ke do
  begin
    if (i > 1) and (e[i] <> e[i-1]) then inc(t);
    if pe[i] > 0 then a[pe[i]]:=t
    else b[-pe[i]]:=t;
  end;
  SortA(1,n);
  fillchar(s,sizeof(s),0);
  modify(1,1);
  ans:=0;
  for i:=1 to n do
  begin
    f[i]:=0;
    f[i]:=(findsum(b[i])-findsum(a[i])+md) mod md;
    modify(b[i]+1,f[i]);
    if b[i] = t then ans:=(ans+f[i]) mod md;
  end;
  writeln(ans);
  close(input);
  close(output);
end.