var
  tx,nn,n,x:longint;

begin
  read(x);
  if (x=3)then begin
    writeln(5);
    exit;
  end;
  for nn:=1 to 100 do begin
    n:=2*nn-1;
    tx:=(n*n+1)div 2;
    if (tx>=x)then begin
      writeln(n);
      exit;
    end;
  end;
end.