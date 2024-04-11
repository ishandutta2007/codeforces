{$R-,S-,Q-,I-,O+}
var
  a,b: array [0..100100] of longint;
  s: ansistring;
  k,ans,cur,n,i: longint;
begin
  readln(s);
  n:=length(s);
  a[0]:=0;
  for i:=1 to n do
    if s[i] in ['A'..'Z'] then a[i]:=a[i-1]+1
    else a[i]:=a[i-1];
  b[0]:=0;
  for i:=1 to n do
    if s[i] in ['A'..'Z'] then b[i]:=b[i-1]
    else b[i]:=b[i-1]+1;
  ans:=maxlongint;
  for k:=0 to n do
  begin
    cur:=b[k]+a[n]-a[k];
    if cur < ans then ans:=cur;
  end;
  writeln(ans);
end.