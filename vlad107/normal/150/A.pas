var
  t:array[0..500]of int64;
  n,m,i:int64;
  kt:longint;

begin
  read(n);
  m:=n;
  i:=2;
  kt:=0;
  while (i*i<=m)do 
    if (n mod i=0)then begin
      inc(kt);
      t[kt]:=i;
      n:=n div i;
    end else inc(i);
  if (n>1)then begin
    inc(kt);
    t[kt]:=n;
  end;
  if (kt=2)then begin
    writeln(2);
    exit;
  end;
  writeln(1);
  if (kt<2)
    then writeln(0)
    else writeln(t[1]*t[2]);
end.