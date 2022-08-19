{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
const inf = round(1e14);
var
  u,l,r,e,ans: int64;
  i: longint;
  x: array [0..100010] of int64;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(l,r);
  i:=1; e:=1;
  x[1]:=0;
  while i <= e do
  begin
    if x[i]*10+4 <= inf then
    begin
      inc(e);
      x[e]:=x[i]*10+4;
    end;
    if x[i]*10+7 <= inf then
    begin
      inc(e);
      x[e]:=x[i]*10+7;
    end;
    inc(i);
  end;
  ans:=0;
  for i:=1 to e do
    if x[i] >= l then
    begin
      if x[i] < r then u:=x[i]
      else u:=r;
      ans:=ans+x[i]*(u-l+1);
      l:=x[i]+1;
      if x[i] >= r then break;
    end;
  writeln(ans);
  close(input);
  close(output);
end.