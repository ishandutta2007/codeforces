var
  a:array[0..500500]of longint;
  ans,n,i:longint;

begin
  read(n);
  for i:=1 to n do read(a[i]);
  if (n=1)or(n and 1=0)then begin
    writeln(-1);
    exit;
  end;
  ans:=0;
  for i:=n downto 1 do begin
    if (2*i+1>n)then continue;
    while (a[2*i]<>0)or(a[2*i+1]<>0)do begin
      inc(ans);
      if (a[2*i]<>0)then dec(a[2*i]);
      if (a[2*i+1]<>0)then dec(a[2*i+1]);
      if (a[i]<>0)then dec(a[i]);
    end;
  end;
  inc(ans,a[1]);
  writeln(ans);
end.