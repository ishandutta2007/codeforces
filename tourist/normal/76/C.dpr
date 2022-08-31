{$R-,S-,Q-,I-,O+}
var
  dead,ans,n,k,mt,i,j,ms,q,ft: longint;
  sum,t: array [0..4444444] of int64;
  was: array [0..23] of boolean;
  a: array [0..200010] of longint;
  s: ansistring;
  last,c: array [0..23] of longint;
  next: array [0..200010,0..23] of longint;
  g: array [0..23,0..23] of longint;
begin
  readln(n,k,mt);
  readln(s);
  for i:=1 to n do a[i]:=Ord(s[i])-64;
  fillchar(was,sizeof(was),False);
  for i:=1 to n do was[a[i]]:=True;
  dead:=0;
  for i:=1 to k do
    if not was[i] then dead:=dead or (1 shl (i-1));
  for i:=1 to k do read(c[i]);
  for i:=1 to k do
    if not was[i] then c[i]:=0;
  for i:=1 to k do
    for j:=1 to k do read(g[i,j]);
  for i:=1 to k do last[i]:=n+1;
  for i:=n downto 1 do
  begin
    for j:=1 to k do next[i,j]:=last[j];
    last[a[i]]:=i;
  end;
  fillchar(t,sizeof(t),0);
  for i:=1 to n do
    for j:=1 to k do
      if next[i,j] <= n then
      begin
        ms:=1 shl k-1;
        for q:=1 to k do
          if next[i,q] < next[i,j] then ms:=ms xor (1 shl (q-1));
        if ms and (1 shl (a[i]-1)) = 0 then continue;
        ft:=g[a[i],j];
        if j <> a[i] then
        begin
          inc(t[ms xor (1 shl (j-1)) xor (1 shl (a[i]-1))],ft);
          dec(t[ms xor (1 shl (j-1))],ft);
          dec(t[ms xor (1 shl (a[i]-1))],ft);
          inc(t[ms],ft);
        end else
        begin
          dec(t[ms xor (1 shl (j-1))],ft);
          inc(t[ms],ft);
        end;
      end;
  for j:=1 to k do
    for i:=0 to 1 shl k-1 do
      if i and (1 shl (j-1)) <> 0 then
        inc(t[i xor (1 shl (j-1))],t[i]);
  for i:=1 shl k-1 downto 0 do
  begin
    sum[i]:=0;
    for j:=1 to k do
      if i and (1 shl (j-1)) = 0 then
      begin
        sum[i]:=sum[i xor (1 shl (j-1))]+c[j];
        break;
      end;
  end;
  ans:=0;
  for i:=1 to 1 shl k-1 do
    if i and dead = 0 then
      if t[i]+sum[i] <= mt then inc(ans);
  writeln(ans);
end.