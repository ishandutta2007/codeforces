var
  n,m,km,k0,i:longint;
  a:array[1..100000] of longint;

begin
  read(n);
  km:=0;m:=-1000000;
  k0:=0;
  for i:=1 to n do begin
    read(a[i]);
    if (a[i]=0)then inc(k0);
    if (a[i]<0)then begin
      inc(km);
      if (a[i]>m) then m:=a[i];
    end;
  end;
  if (n=1) then begin
    writeln(a[1]);
    exit;
  end;
  if (k0+km=n) and (km<2)then begin
    writeln(0);
    exit;
  end;
  k0:=0;
  if (km mod 2 = 0) then m:=-10000000;
  for i:=1 to n do begin
    if (a[i]=0)then continue;
    if (a[i]=m) and (k0=0)then begin
      k0:=1;
      continue;
    end;
    write(a[i],' ');
  end;
end.