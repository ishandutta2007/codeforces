{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,i,j,k: longint;
  a,d: array [0..1010] of longint;
  g: array [0..1010,0..1010] of longint;
begin
  read(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do read(d[i]);
  for i:=1 to n do
    for j:=1 to n do
      if (i = j) or (abs(i-j) = d[i]) or (abs(i-j) = d[j]) then g[i,j]:=0
      else g[i,j]:=1000000;
  for k:=1 to n do
    for i:=1 to n do
      for j:=1 to n do
        if g[i,k]+g[k,j] < g[i,j] then g[i,j]:=g[i,k]+g[k,j];
  for i:=1 to n do
    if g[i,a[i]] > 0 then
    begin
      writeln('NO');
      halt;
    end;
  writeln('YES');
end.