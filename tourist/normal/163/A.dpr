{$R-,S-,Q-,I-,O+}
const md = round(1e9+7);
var
  a,b: ansistring;
  f,s: array [0..5010] of longint;
  ans,n,m,i,j: longint;
begin
  readln(a);
  readln(b);
  n:=length(a);
  m:=length(b);
  for j:=0 to m do s[j]:=1;
  ans:=0;
  for i:=1 to n do
  begin
    f[0]:=1;
    for j:=1 to m do
      if a[i] <> b[j] then f[j]:=0
      else f[j]:=s[j-1];
    s[0]:=1;
    for j:=1 to m do
    begin
      s[j]:=s[j-1]+f[j];
      if s[j] >= md then dec(s[j],md);
    end;
    ans:=ans+s[m];
    if ans >= md then dec(ans,md);
  end;
  writeln((ans+md-n) mod md);
end.