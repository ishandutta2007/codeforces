{$R-,S-,Q-,I-,O+}
var
  h,pw: array [0..200010] of int64;
  s: ansistring;
  q,j,c,co,n,i: longint;
  ans,sum: int64;
  pred,last,pr,ne,lcp,a: array [0..200010] of longint;

function cmp(i,j:longint):longint;
var
  ll,rr,mid: longint;
begin
  if i = j then cmp:=0 else
  begin
    rr:=n-i+1;
    if n-j+1 < rr then rr:=n-j+1;
    ll:=0;
    while ll < rr do
    begin
      mid:=(ll+rr+1) shr 1;
      if h[i+mid-1]-h[i-1]*pw[mid] = h[j+mid-1]-h[j-1]*pw[mid] then ll:=mid
      else rr:=mid-1;
    end;
    if rr = n-i+1 then cmp:=-rr-1 else
    if rr = n-j+1 then cmp:=rr+1 else
    if s[i+rr] < s[j+rr] then cmp:=-rr-1
    else cmp:=rr+1;
  end;
end;

procedure Sort(l,r:longint);
var
  i,j,x,tmp: longint;
begin
  i:=l; j:=r;
  x:=a[l+random(r-l+1)];
  repeat
    while cmp(a[i],x) < 0 do inc(i);
    while cmp(x,a[j]) < 0 do dec(j);
    if i <= j then
    begin
      tmp:=a[i]; a[i]:=a[j]; a[j]:=tmp;
      inc(i); dec(j);
    end;
  until i > j;
  if l < j then Sort(l,j);
  if i < r then Sort(i,r);
end;

begin
  randomize;
  co:=91249129+random(100)*100;
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  readln(s);
  n:=length(s);
  pw[0]:=1;
  for i:=1 to n do pw[i]:=pw[i-1]*co;
  h[0]:=0;
  for i:=1 to n do h[i]:=h[i-1]*co+Ord(s[i]);
  for i:=1 to n do a[i]:=i;
  Sort(1,n);
  for i:=1 to n-1 do lcp[i]:=abs(cmp(a[i],a[i+1]))-1;
  fillchar(last,sizeof(last),0);
  for i:=1 to n-1 do
  begin
    pred[i]:=last[lcp[i]];
    last[lcp[i]]:=i;
  end;
  for i:=0 to n+1 do
  begin
    pr[i]:=i-1;
    ne[i]:=i+1;
  end;
  ans:=int64(n)*(n+1) div 2;
  sum:=0;
  for q:=n-1 downto 1 do
  begin
    j:=last[q];
    while j > 0 do
    begin
      c:=j-pr[j];
      sum:=sum-int64(c)*(c+1) div 2;
      c:=ne[j]-j;
      sum:=sum-int64(c)*(c+1) div 2;
      c:=ne[j]-pr[j];
      sum:=sum+int64(c)*(c+1) div 2;
      pr[ne[j]]:=pr[j];
      ne[pr[j]]:=ne[j];
      j:=pred[j];
    end;
    ans:=ans+sum;
  end;
  writeln(ans);
  close(input);
  close(output);
end.