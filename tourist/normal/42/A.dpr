{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  s,n,v,i,b: longint;
  ans: extended;
  a: array [0..10010] of longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,v);
  for i:=1 to n do read(a[i]);
  ans:=1e9; s:=0;
  for i:=1 to n do
  begin
    read(b);
    if b/a[i] < ans then ans:=b/a[i];
    inc(s,a[i]);
  end;
  ans:=ans*s;
  if ans > v then ans:=v;
  writeln(ans:0:17);
  close(input);
  close(output);
end.