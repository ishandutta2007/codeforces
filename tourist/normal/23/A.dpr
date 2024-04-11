{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,i,j,ans: longint;
  s: ansistring;
  f: array [0..110,0..110] of longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  readln(s);
  n:=length(s);
  fillchar(f,sizeof(f),0);
  for i:=n downto 1 do
    for j:=n downto 1 do
      if s[i] = s[j] then f[i,j]:=f[i+1,j+1]+1
      else f[i,j]:=0;
  ans:=0;
  for i:=1 to n do
    for j:=i+1 to n do
      if f[i,j] > ans then ans:=f[i,j];
  writeln(ans);
  close(input);
  close(output);
end.