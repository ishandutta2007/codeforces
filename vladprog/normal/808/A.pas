uses math;

var
  n,k,m,ans:longint;

begin
  read(n);
  k:=round(int(log10(n)));
  m:=round(power(10,k));
  ans:=(n+m-1) div m * m-n;
  if ans=0 then
    begin
      inc(n);
      k:=round(int(log10(n)));
      m:=round(power(10,k));
      ans:=(n+m-1) div m * m-n;
      inc(ans)
    end;
  writeln(ans)
end.