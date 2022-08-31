{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  cur,ans,ll,rr,a,b,s,best,mid: int64;
  d: longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(ll,rr);
  ans:=0; s:=1;
  for d:=1 to 10 do
  begin
    a:=ll; b:=rr;
    if a < s then a:=s;
    if b > s*10-1 then b:=s*10-1;
    if a <= b then
    begin
      mid:=s*5;
      if a > mid then best:=a else
      if b < mid then best:=b
      else best:=mid;
      cur:=best*(s*10-best-1);
      if cur > ans then ans:=cur;
    end;
    s:=s*10;
  end;
  writeln(ans);
  close(input);
  close(output);
end.