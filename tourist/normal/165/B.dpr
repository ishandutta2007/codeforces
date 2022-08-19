{$R-,S-,Q-,I-,O+}
var
  n,k,ll,rr,mid,x,y: int64;
begin
  read(n,k);
  ll:=1; rr:=round(1e18);
  while ll < rr do
  begin
    mid:=(ll+rr) shr 1;
    x:=0; y:=mid;
    while y > 0 do
    begin
      x:=x+y;
      y:=y div k;
    end;
    if x >= n then rr:=mid
    else ll:=mid+1;
  end;
  writeln(ll);
end.