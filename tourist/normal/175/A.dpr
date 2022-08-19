{$R-,S-,Q-,I-,O+}
var
  s: ansistring;
  i,j,k,v,q,n: longint;
  f: array [0..333,0..4] of longint;
begin
  readln(s);
  n:=length(s);
  for i:=0 to n do
    for j:=0 to 3 do f[i,j]:=-1000000000;
  f[0,0]:=0;
  for i:=1 to n do
    for j:=1 to 3 do
      for k:=i-8 to i do
      begin
        if k < 1 then continue;
        if (k < i) and (s[k] = '0') then continue;
        v:=0;
        for q:=k to i do v:=v*10+Ord(s[q])-48;
        if v > 1000000 then continue;
        if f[k-1,j-1]+v > f[i,j] then f[i,j]:=f[k-1,j-1]+v;
      end;
  if f[n,3] < 0 then writeln('-1')
  else writeln(f[n,3]);
end.