var
  s,f,res,n,i:longint;
  a:array[0..11111]of longint;
begin
  read(n);
  for i:=1 to n do read(a[i]);
  res:=0;
  for i:=1 to n do begin
    s:=i;f:=i;
    while (f<n)and(a[f+1]<=a[f])do inc(f);
    while (s>1)and(a[s-1]<=a[s])do dec(s);
    if (f-s+1>res)then res:=f-s+1;
  end;
  writeln(res);
end.