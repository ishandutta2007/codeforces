{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,i,j: longint;
  c,ans: int64;
  a: array [0..1000010] of longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  for i:=1 to n do read(a[i]);
  ans:=0; i:=1;
  while i <= n do
  begin
    j:=i;
    while (j <= n) and (a[i] = a[j]) do inc(j);
    c:=j-i;
    ans:=ans+int64(c)*(c+1) div 2;
    i:=j;
  end;
  writeln(ans);
  close(input);
  close(output);
end.