uses math;

var
  n,k,s,a,ii:int64;
  i:longint;

begin
  read(n,k);
  s:=0;
  for i:=1 to n do
    begin
      read(a);
      ii:=i;
      inc(s,a*min(min(k,n-k+1),min(ii,n-ii+1)))
    end;
  writeln(s/(n-k+1))
end.