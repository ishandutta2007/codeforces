var
  sum,min,n,i,x:longint;

begin
  read(n);
  min:=maxlongint;
  sum:=0;
  for i:=1 to n do begin
    read(x);
    inc(sum,x);
    if (x and 1=1)and(x<min)then min:=x;
  end;
  if (min=maxlongint)
    then writeln(0)
    else begin
      if (sum and 1=0)then dec(sum,min);
      writeln(sum);
    end;
end.