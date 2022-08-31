{$R+,S+,Q+,I+,O-}
const md = round(1e9+7);
var
  n,odd,even,ans,i,cur: longint;
begin
  read(n);
  odd:=1; even:=1;
  ans:=0;
  for i:=1 to n do
  begin
    if i and 1 = 1 then cur:=even
    else cur:=odd;
    ans:=ans+cur;
    if ans >= md then dec(ans,md);
    if i and 1 = 1 then odd:=(odd+cur) mod md
    else even:=(even+cur) mod md;
  end;
  writeln(ans);
end.