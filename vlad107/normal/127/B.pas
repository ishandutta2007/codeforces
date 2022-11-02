var
  res,n,i,j,x:longint;
  a:array[0..500500]of longint;

begin
  read(n);
  for i:=1 to n do begin
    read(x);
    inc(a[x]);
  end;
  i:=1;
  res:=0;
  while (i<=100)do begin
    if (a[i]<2)then begin
      inc(i);continue;
    end;
    x:=-1;
    dec(a[i],2);
    for j:=i to 100 do if (a[j]>1)then begin
      x:=j;break;
    end;
    if (x<0)then break;
    dec(a[x],2);
    inc(res);
  end;
  writeln(res);
end.