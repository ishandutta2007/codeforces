var
  y,n,m,i,x,kol:longint;
  a,was:array[0..500500]of longint;

begin
  read(n,m);
  fillchaR(was,sizeof(was),$0);
  kol:=0;x:=0;y:=0;
  for i:=1 to n do begin
    read(a[i]);
    inc(was[a[i]]);
    if (was[a[i]]<>1)then continue;
    inc(kol);
    if (kol=m)then begin
      x:=1;y:=i;
      break;
    end;
  end;
  if (x=0)then begin
    writeln('-1 -1');
    exit;
  end;
  while (was[a[x]]>1)do begin
    dec(was[a[x]]);
    inc(x);
  end;
  writeln(x,' ',y);
end.