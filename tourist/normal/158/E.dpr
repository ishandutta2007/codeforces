{$R-,S-,Q-,I-,O+}
var
  ans,n,k,i,j,u: longint;
  t,d: array [0..4010] of longint;
  f: array [0..4010,0..4010] of longint;
begin
  read(n,k);
  for i:=1 to n do read(t[i],d[i]);
  t[n+1]:=86401; d[n+1]:=1;
  for i:=0 to n do
    for j:=0 to k do f[i,j]:=123456;
  f[0,0]:=1; ans:=0;
  for i:=0 to n do
    for j:=0 to k do
      if f[i,j] <= 86400 then
      begin
        if t[i+1]-f[i,j] > ans then ans:=t[i+1]-f[i,j];
        if f[i,j] < f[i+1,j+1] then f[i+1,j+1]:=f[i,j];
        if f[i,j] <= t[i+1] then u:=t[i+1]+d[i+1]
        else u:=f[i,j]+d[i+1];
        if u < f[i+1,j] then f[i+1,j]:=u;
      end;
  writeln(ans);
end.