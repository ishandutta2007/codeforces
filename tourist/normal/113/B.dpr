{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
var
  s,a,b: ansistring;
  n,na,nb,i,j,max,ans: longint;
  f,fa,fb: array [0..2010,0..2010] of longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  readln(s);
  readln(a);
  readln(b);
  n:=length(s);
  na:=length(a);
  nb:=length(b);
  fillchar(f,sizeof(f),0);
  for i:=n downto 1 do
    for j:=n downto 1 do
      if s[i] = s[j] then f[i,j]:=f[i+1,j+1]+1
      else f[i,j]:=0;
  fillchar(fa,sizeof(fa),0);
  for i:=n downto 1 do
    for j:=na downto 1 do
      if s[i] = a[j] then fa[i,j]:=fa[i+1,j+1]+1
      else fa[i,j]:=0;
  fillchar(fb,sizeof(fb),0);
  for i:=n downto 1 do
    for j:=nb downto 1 do
      if s[i] = b[j] then fb[i,j]:=fb[i+1,j+1]+1
      else fb[i,j]:=0;
  ans:=0;
  for i:=1 to n do
  begin
    max:=na-1;
    if nb-1 > max then max:=nb-1;
    for j:=1 to i-1 do
      if f[i,j] > max then max:=f[i,j];
    for j:=i+max to n do
      if (fa[i,1] = na) and (fb[j-nb+1,1] = nb) then inc(ans);
  end;
  writeln(ans);
  close(input);
  close(output);
end.