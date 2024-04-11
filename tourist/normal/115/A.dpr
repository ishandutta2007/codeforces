{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,i,ans,cur,p: longint;
  a: array [0..2222] of longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  for i:=1 to n do read(a[i]);
  ans:=0;
  for i:=1 to n do
  begin
    cur:=0; p:=i;
    while p <> -1 do
    begin
      inc(cur);
      p:=a[p];
    end;
    if cur > ans then ans:=cur;
  end;
  writeln(ans);
  close(input);
  close(output);
end.