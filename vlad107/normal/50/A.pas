var
  n,m,rr,res:longint;

  procedure solve(n,m:longint);
    begin
      if (m and 1=0)then begin
        res:=n*m div 2;
        exit;
      end else begin
        res:=n*(m-1) div 2;
        res:=res+(n div 2);
        exit;
      end;
    end;

begin 
  read(n,m);
  solve(n,m);rr:=res;
  solve(m,n);
  if (rr>res)then writeln(rr)else writeln(res);
end.