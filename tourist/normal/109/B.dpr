{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
var
  i,j,n,pl,pr,vl,vr,k,tmp,x,y,lg1,rg1,lg2,rg2: longint;
  cnt: int64;
  a: array [0..10010] of longint;

procedure rec(v,w:longint);
begin
  inc(n);
  a[n]:=w;
  if v = 9 then exit;
  rec(v+1,w*10+4);
  rec(v+1,w*10+7);
end;

function count(a,b,c,d:longint):longint;
begin
  if c > a then a:=c;
  if d < b then b:=d;
  if a > b then count:=0
  else count:=b-a+1;
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(pl,pr,vl,vr,k);
  n:=0;
  rec(1,4);
  rec(1,7);
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if a[i] > a[j] then
      begin
        tmp:=a[i]; a[i]:=a[j]; a[j]:=tmp;
      end;
  a[0]:=0; a[n+1]:=maxlongint;
  cnt:=0;
  for i:=1 to n-k+1 do
  begin
    lg1:=a[i-1]+1; rg1:=a[i];
    lg2:=a[i+k-1]; rg2:=a[i+k]-1;
    x:=count(lg1,rg1,pl,pr);
    y:=count(lg2,rg2,vl,vr);
    cnt:=cnt+int64(x)*y;
    x:=count(lg1,rg1,vl,vr);
    y:=count(lg2,rg2,pl,pr);
    cnt:=cnt+int64(x)*y;
    if (k = 1) and (a[i] >= pl) and (a[i] <= pr) and (a[i] >= vl) and (a[i] <= vr) then
      dec(cnt);
  end;
  writeln(cnt/(pr-pl+1)/(vr-vl+1):0:17);
  close(input);
  close(output);
end.