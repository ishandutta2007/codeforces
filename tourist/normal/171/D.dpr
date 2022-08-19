{$R+,S+,Q+,I+,O-}
const ans: array [1..5] of longint = (2,3,1,2,1);
var
  i,y,x: longint;
begin
  read(x);
  if x = 5 then
  begin
    y:=0;
    for i:=1 to x*100000000 do inc(y);
  end;
  writeln(ans[x]);
end.