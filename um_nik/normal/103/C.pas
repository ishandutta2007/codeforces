var n,k,x,t:int64;
i,p:integer;
begin
readln(n,k,p);
if 2*k>=n then
  begin
  for i:=1 to p do
    begin
    readln(x);
    if (x mod 2=1) and ((x+1) div 2<=n-k) then write('.') else write('X');
    end;
  end else
  begin
  if n mod 2=1 then
    begin
    n-=1;
    k-=1;
    end;
  for i:=1 to p do
    begin
    readln(x);
    if k=-1 then
      begin
      write('.');
      continue;
      end;
    if (x=n+1) or ((x mod 2=0) and ((n+2-x) div 2<=k)) then write('X') else write('.');
    end;
  end;
end.