{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,i: longint;
  ans,cur,max,res: int64;
  a: array [0..100010] of int64;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  for i:=1 to n do read(a[i]);
  ans:=0;
  for i:=1 to n do dec(ans,a[i]);
  cur:=0; max:=0;
  res:=0;
  for i:=1 to n do
  begin
    inc(cur,a[i]);
    if cur < max then max:=cur;
    if cur-max > res then res:=cur-max;
  end;
  writeln(ans+2*res);
  close(input);
  close(output);
end.