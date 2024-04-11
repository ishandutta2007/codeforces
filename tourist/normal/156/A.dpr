{$R-,S-,Q-,I-,O+}
var
  n,m,i,j,ans: longint;
  f: array [0..2010,0..2010] of longint;
  s,t: ansistring;
begin
  readln(s);
  readln(t);
  n:=length(s);
  m:=length(t);
  fillchar(f,sizeof(f),0);
  for i:=n downto 1 do
    for j:=m downto 1 do
      if s[i] = t[j] then f[i,j]:=f[i+1,j+1]+1
      else f[i,j]:=f[i+1,j+1];
  ans:=0;
  for i:=1 to n do
    for j:=1 to m do
      if f[i,j] > ans then ans:=f[i,j];
  writeln(m-ans);
end.