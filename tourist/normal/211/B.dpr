{$R-,S-,Q-,I-,O+}
var
  s: array [0..1000010] of char;
  last: array [#0..#255] of longint;
  j,ii,lo,hi,tt,qq,mx,ll,rr,mid,mask,n,i,m: longint;
  a: array [0..26000010] of longint;
  x: array [0..33] of longint;
  y: array [0..33] of char;
  ch,c: char;

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
      inc(i); dec(j);
    end;
  until i > j;
  if l < j then Sort(l,j);
  if i < r then Sort(i,r);
end;

begin
  randomize;
  read(ch);
  while not (ch in ['a'..'z']) do read(ch);
  n:=0;
  while ch in ['a'..'z'] do
  begin
    inc(n);
    s[n]:=ch;
    read(ch);
  end;
  s[0]:=' ';
  for c:=#0 to #255 do last[c]:=n+1;
  for i:=1 to 26 do
  begin
    x[i]:=n+1;
    y[i]:=Chr(i+96);
  end;
  m:=0;
  for i:=n downto 1 do
  begin
    last[s[i]]:=i;
    for j:=1 to 26 do
      if y[j] = s[i] then
      begin
        for ii:=j downto 2 do
        begin
          x[ii]:=x[ii-1];
          y[ii]:=y[ii-1];
        end;
        x[1]:=i;
        y[1]:=s[i];
        break;
      end;
    mx:=last[s[i-1]];
    mask:=0;
    for ii:=1 to 26 do
    begin
      if x[ii] >= mx then break;
      mask:=mask+(1 shl (Ord(y[ii])-97));
      inc(m);
      a[m]:=mask;
    end;
  end;
  Sort(1,m);
  read(tt);
  for qq:=1 to tt do
  begin
    read(ch);
    while not (ch in ['a'..'z']) do read(ch);
    mask:=0;
    while ch in ['a'..'z'] do
    begin
      inc(mask,1 shl (Ord(ch)-97));
      read(ch);
    end;
    ll:=1; rr:=m+1;
    while ll < rr do
    begin
      mid:=(ll+rr) shr 1;
      if a[mid] < mask then ll:=mid+1
      else rr:=mid;
    end;
    lo:=ll;
    ll:=0; rr:=m;
    while ll < rr do
    begin
      mid:=(ll+rr+1) shr 1;
      if a[mid] > mask then rr:=mid-1
      else ll:=mid;
    end;
    hi:=ll;
    if lo > hi then writeln(0)
    else writeln(hi-lo+1);
  end;
end.