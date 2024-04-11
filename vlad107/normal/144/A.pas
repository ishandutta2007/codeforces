var
  tmp,ans,n,i,max,min:longint;
  a:array[0..500500]of longint;

begin
  read(n);
  max:=0;
  min:=101;
  for i:=1 to n do begin
    read(a[i]);
    if (a[i]>max)then max:=a[i];
    if (a[i]<min)then min:=a[i];
  end;
  i:=1;
  while (a[i]<>max)do inc(i);
  ans:=i-1;
  while (i>1)do begin
    tmp:=a[i];a[i]:=a[i-1];a[i-1]:=tmp;
    dec(i);
  end;
  i:=n;
  while (a[i]<>min)do dec(i);
  inc(ans,n-i);
  writeln(ans);
end.