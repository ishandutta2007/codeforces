{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,kd,x,a,b,c: longint;
  d: array [0..100010] of longint;
  cur,min,max: int64;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  kd:=0;
  for x:=1 to n do
    if x*x > n then break else
    if n mod x = 0 then
    begin
      inc(kd);
      d[kd]:=x;
      if x*x < n then
      begin
        inc(kd);
        d[kd]:=n div x;
      end;
    end;
  min:=round(9e18);
  max:=-1;
  for a:=1 to kd do
    for b:=1 to kd do
    begin
      if n div d[a] mod d[b] <> 0 then continue;
      c:=n div d[a] div d[b];
      cur:=int64(d[a]+1)*(d[b]+2)*(c+2)-n;
      if cur < min then min:=cur;
      if cur > max then max:=cur;
    end;
  writeln(min,' ',max);
  close(input);
  close(output);
end.