var
  s,sum,n,i,res:longint;
  a:array[1..110000]of longint;
begin
  read(n);
  sum:=0;
  for i:=1 to n do begin
    read(a[i]);
    inc(sum,a[i]);
  end;
  s:=0;
  res:=0;
  for i:=1 to n-1 do begin
    inc(s,a[i]);
    if (s+s=sum)then inc(res);
  end;
  writeln(res);
end.