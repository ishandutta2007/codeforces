var
  ans:longint;
  x,k,b,n,t:int64;

begin
  read(k,b,n,t);
  x:=1;
  ans:=n+1;
  while (t>=x)and(ans>0)do begin
    x:=x*k+b;
    dec(ans);
  end;
  writeln(ans);
end.