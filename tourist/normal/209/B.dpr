{$R+,S+,Q+,I+,O-}
var
  a,b,c,tmp,ans: int64;
begin
  read(a,b,c);
  if a > b then begin tmp:=a; a:=b; b:=tmp; end;
  if a > c then begin tmp:=a; a:=c; c:=tmp; end;
  if b > c then begin tmp:=b; b:=c; c:=tmp; end;
  ans:=round(1e18);
  if a and 1 = b and 1 then
    if b < ans then ans:=b;
  if a and 1 = c and 1 then
    if c < ans then ans:=c;
  if b and 1 = c and 1 then
    if c < ans then ans:=c;
  writeln(ans);
end.