var
  x,m,n,k,res,i:longint;
  a:array[0..100000]of longint;
begin
  read(n,k,m);
  res:=0;
  for i:=1 to m do read(a[i]);
  x:=k;
  i:=1;
  while (x<=n)or(i<=m)do begin
    if (i<=m)and(x>a[i])then begin
      x:=a[i]+k;
      inc(i);
      inc(res);
      continue;
    end;
    if (i<=m)and(x=a[i])then inc(i);
    inc(res);
    inc(x,k);
  end;
  writeln(res);
end.