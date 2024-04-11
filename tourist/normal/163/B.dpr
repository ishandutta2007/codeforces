{$R-,S-,Q-,I-,O+}
{$M 50000000}
var
  it,n,k,h,i,j: longint;
  m,v,num,res,ans: array [0..200010] of longint;
  ll,rr,mid: extended;

procedure Sort(l,r:longint);
var
  i,j,pp,x,xx,tmp: longint;
begin
  i:=l; j:=r;
  pp:=l+random(r-l+1);
  x:=m[pp]; xx:=v[pp];
  repeat
    while (m[i] < x) or (m[i] = x) and (v[i] < xx) do inc(i);
    while (m[j] > x) or (m[j] = x) and (v[j] > xx) do dec(j);
    if i <= j then
    begin
      tmp:=m[i]; m[i]:=m[j]; m[j]:=tmp;
      tmp:=v[i]; v[i]:=v[j]; v[j]:=tmp;
      tmp:=num[i]; num[i]:=num[j]; num[j]:=tmp;
      inc(i); dec(j);
    end;
  until i > j;
  if l < j then Sort(l,j);
  if i < r then Sort(i,r);
end;

begin
  randomize;
  read(n,k,h);
  for i:=1 to n do read(m[i]);
  for i:=1 to n do read(v[i]);
  for i:=1 to n do num[i]:=i;
  Sort(1,n);
  fillchar(ans,sizeof(ans),0);
  ll:=0; rr:=1e9+7;
  for it:=1 to 200 do
  begin
    mid:=(ll+rr)*0.5;
    j:=k;
    for i:=n downto 1 do
      if j*h <= mid*v[i] then
      begin
        res[j]:=num[i];
        dec(j);
        if j = 0 then break;
      end;
    if j > 0 then ll:=mid else
    begin
      rr:=mid;
      for i:=1 to k do ans[i]:=res[i];
    end;
  end;
  for i:=1 to k-1 do write(ans[i],' ');
  writeln(ans[k]);
end.