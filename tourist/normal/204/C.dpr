{$R-,S-,Q-,I-,O+}
var
  n,i: longint;
  tot: int64;
  ans: extended;
  a,b: ansistring;
  s,w: array [0..200010] of int64;
  ch: char;
begin
  readln(n);
  readln(a);
  readln(b);
  ans:=0;
  for ch:='A' to 'Z' do
  begin
    s[0]:=0;
    for i:=1 to n do
      if b[i] = ch then s[i]:=s[i-1]+i
      else s[i]:=s[i-1];
    w[0]:=0;
    for i:=1 to n do
      if b[i] = ch then w[i]:=w[i-1]+1
      else w[i]:=w[i-1];
    for i:=1 to n do
      if a[i] = ch then
      begin
        ans:=ans+s[i]*(n-i+1);
        ans:=ans+int64(i)*((w[n]-w[i])*(n+1)-(s[n]-s[i]));
      end;
  end;
  tot:=0;
  for i:=1 to n do tot:=tot+int64(i)*i;
  writeln(ans/tot:0:17);
end.