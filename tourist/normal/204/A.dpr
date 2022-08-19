{$R-,S-,Q-,I-,O+}
var
  ll,rr,lo,hi,lg,rg,l,r,ans: int64;
  d: longint;
begin
  read(ll,rr);
  ans:=0;
  while (ll <= rr) and (ll <= 9) do
  begin
    inc(ans);
    inc(ll);
  end;
  for d:=1 to 9 do
  begin
    if ll mod 10 <= d then lo:=ll div 10
    else lo:=ll div 10+1;
    if rr mod 10 >= d then hi:=rr div 10
    else hi:=rr div 10-1;
    if lo > hi then continue;
    l:=d; r:=d;
    while l <= hi do
    begin
      lg:=lo; rg:=hi;
      if l > lg then lg:=l;
      if r < rg then rg:=r;
      if lg <= rg then ans:=ans+(rg-lg+1);
      if l > hi div 10 then break;
      l:=l*10;
      r:=r*10+9;
    end;
  end;
  writeln(ans);
end.