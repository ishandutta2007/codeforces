{$R-,S-,Q-,I-,O+}
const co = 1000000;
var
  n,m,i,j,s,ans: longint;
  a,b,pz,c: array [0..2000010] of longint;
begin
  read(n,m);
  for i:=1 to n do read(a[i]);
  for i:=1 to m do read(b[i]);
  fillchar(pz,sizeof(pz),0);
  for i:=1 to m do pz[b[i]]:=i;
  a[n+1]:=a[1];
  for i:=1 to n do
    if (pz[a[i]] = 0) or (pz[a[i+1]] = 0) then c[i]:=10*co else
    begin
      c[i]:=pz[a[i+1]]-pz[a[i]];
      if c[i] < 0 then inc(c[i],m);
    end;
  ans:=0;
  for i:=1 to n do
    if pz[a[i]] > 0 then ans:=1;
  if ans = 0 then
  begin
    writeln(0);
    halt;
  end;
  for i:=1 to n do c[i+n]:=c[i];
  j:=0; s:=0;
  for i:=1 to n do
  begin
    while (j < n+n) and (s+c[j+1] < m) do
    begin
      inc(j);
      s:=s+c[j];
    end;
    if j-i+2 > ans then ans:=j-i+2;
    s:=s-c[i];
  end;
  if ans > n then ans:=n;
  if ans > m then ans:=m;
  writeln(ans);
end.