var
  t:array[0..5000]of longint;
  res,n,m,i,kt:longint;

begin
  read(n);
  m:=n;
  i:=2;
  kt:=0;
  while (i*i<=m)do begin
    if (n mod i=0)then begin
      inc(kt);
      t[kt]:=i;
      while (n mod i=0)do n:=n div i;
    end;
    inc(i);
  end;
  if (n>1)then begin
    inc(kt);
    t[kt]:=n;
  end;
  n:=m;
  res:=n;
  for i:=1 to kt do begin
    while (n mod t[i]=0)do begin 
      inc(res,n div t[i]);
      n:=n div t[i];
    end;
  end;
  writeln(res);
end.