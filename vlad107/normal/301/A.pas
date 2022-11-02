var
  ans,min:int64;
  i,ct,n,x:longint;
begin
  read(n);
  min:=1000000000;ct:=0;
  for i:=1 to 2*n-1 do begin
    read(x);
    ans:=ans+abs(x);
    if (x<0)then inc(ct);
    if (abs(x)<min)then min:=abs(x);
  end;
  if (n mod 2=0)and(ct mod 2=1)then ans:=ans-2*min;
  writeln(ans);
end.