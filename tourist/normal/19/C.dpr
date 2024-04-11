{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
var
  h,step: array [0..100010] of int64;
  pz,last,a,b,num: array [0..100010] of longint;
  t,p,n,i,m,j,ii,jj,len: longint;
  h1,h2: int64;
  ss,pred: array [0..6000010] of longint;

procedure SortA(l,r:longint);
var
  i,j,pp,x,y,tmp: longint;
begin
  i:=l; j:=r;
  pp:=l+random(r-l+1);
  x:=a[pp]; y:=num[pp];
  repeat
    while (a[i] < x) or (a[i] = x) and (num[i] < y) do inc(i);
    while (x < a[j]) or (x = a[j]) and (y < num[j]) do dec(j);
    if i <= j then
    begin
      tmp:=a[i]; a[i]:=a[j]; a[j]:=tmp;
      tmp:=num[i]; num[i]:=num[j]; num[j]:=tmp;
      inc(i); dec(j);
    end;
  until i > j;
  if l < j then SortA(l,j);
  if i < r then SortA(i,r);
end;

begin
  randseed:=8753;
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  for i:=1 to n do
  begin
    read(a[i]);
    b[i]:=a[i];
    num[i]:=i;
  end;
  SortA(1,n);
  for i:=1 to n do pz[num[i]]:=i;
  h[0]:=0;
  for i:=1 to n do h[i]:=h[i-1]*239+b[i];
  step[0]:=1;
  for i:=1 to n do step[i]:=step[i-1]*239;
  fillchar(last,sizeof(last),0);
  m:=0;
  for ii:=n downto 1 do
  begin
    i:=pz[ii];
    for j:=i+1 to n do
      if a[i] = a[j] then
      begin
        jj:=num[j];
        len:=jj-ii;
        if jj+len-1 > n then continue;
        h1:=h[jj-1]-h[ii-1]*step[len];
        h2:=h[jj+len-1]-h[jj-1]*step[len];
        if h1 <> h2 then continue;
        inc(m);
        ss[m]:=ii;
        pred[m]:=last[len];
        last[len]:=m;
      end
      else break;
  end;
  t:=0;
  for p:=1 to n do
  begin
    j:=last[p];
    while j > 0 do
    begin
      if ss[j] > t then t:=ss[j]+p-1;
      j:=pred[j];
    end;
  end;
  writeln(n-t);
  for i:=t+1 to n-1 do write(b[i],' ');
  if t < n then write(b[n]);
  writeln;
  close(input);
  close(output);
end.