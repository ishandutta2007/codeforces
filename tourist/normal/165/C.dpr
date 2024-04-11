{$R-,S-,Q-,I-,O+}
var
  k,n,i: longint;
  ans: int64;
  ch: char;
  c,a,s: array [0..1000010] of longint;
begin
  read(k,ch);
  while (ch <> '0') and (ch <> '1') do read(ch);
  n:=0;
  while ch in ['0','1'] do
  begin
    inc(n);
    a[n]:=Ord(ch)-48;
    read(ch);
  end;
  s[0]:=0;
  for i:=1 to n do s[i]:=s[i-1]+a[i];
  fillchar(c,sizeof(c),0);
  ans:=0;
  for i:=0 to n do
  begin
    if s[i] >= k then ans:=ans+c[s[i]-k];
    inc(c[s[i]]);
  end;
  writeln(ans);
end.