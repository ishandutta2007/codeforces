{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,l,i,x,cur,ans: longint;
  a: array [0..1010] of longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,l);
  for i:=1 to n do read(a[i]);
  ans:=0;
  for x:=l to 1000 do
  begin
    cur:=0;
    for i:=1 to n do inc(cur,a[i] div x);
    if cur*x > ans then ans:=cur*x;
  end;
  writeln(ans);
  close(input);
  close(output);
end.