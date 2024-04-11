{$R-,S-,Q-,I-,O+}
var
  tt,qq,n,i,ans: longint;
  c,c1,c2: char;
  s: ansistring;
  can: array ['a'..'{','a'..'{'] of boolean;
  f: array [0..100010,'a'..'{'] of longint;
begin
  readln(s);
  n:=length(s);
  fillchar(can,sizeof(can),True);
  readln(tt);
  for qq:=1 to tt do
  begin
    readln(c1,c2);
    can[c1,c2]:=False;
    can[c2,c1]:=False;
  end;
  fillchar(f,sizeof(f),50);
  f[0,'{']:=0;
  for i:=1 to n do
  begin
    for c:='a' to '{' do f[i,c]:=f[i-1,c]+1;
    for c:='a' to '{' do
      if can[c,s[i]] then
        if f[i-1,c] < f[i,s[i]] then f[i,s[i]]:=f[i-1,c];
  end;
  ans:=maxlongint;
  for c:='a' to '{' do
    if f[n,c] < ans then ans:=f[n,c];
  writeln(ans);
end.