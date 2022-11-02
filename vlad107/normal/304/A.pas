var
  cc,c,ans,n,a,b:longint;

begin
  read(n);
  for a:=1 to n do 
    for b:=a to n do begin
      c:=a*a+b*b;
      cc:=trunc(sqrt(c));
      if (cc<=n)and(cc*cc=c)then inc(ans);
    end;
  writeln(ans);
end.