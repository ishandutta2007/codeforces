var
  res,n,k,i,ck,x:longint;

begin
  read(n,k);
  res:=0;
  for i:=1 to n do begin
    read(x);
    ck:=0;
    while (x>0)do begin
      if (x mod 10=4)or(x mod 10=7)then inc(ck);
      x:=x div 10;
    end;
    if (ck<=k)then inc(res);
  end;
  writeln(res);
end.