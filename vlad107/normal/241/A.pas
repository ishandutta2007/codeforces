var
  max,ct,d,x,ans,n,k,i:longint;
  dd,xx:array[0..500500]of longint;

begin
  read(n,k);
  max:=0;
  ct:=0;
  ans:=0;
  for i:=1 to n do read(dd[i]);
  for i:=1 to n do read(xx[i]);
  for i:=1 to n do begin
    d:=dd[i];
    x:=xx[i];
    inc(ct,x);
    if (x>max)then max:=x;
    while (ct<d)do begin
      inc(ans,k);
      inc(ct,max);
    end;
    inc(ans,d);
    dec(ct,d);
  end;
  writeln(ans);
end.