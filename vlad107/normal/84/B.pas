var
  n,i,j:longint;
  a:array[0..100500]of longint;
  k,res:int64;

begin
  read(n);
  for i:=1 to n do read(a[i]);
  i:=1;
  res:=0;
  while (i<=n)do begin
    j:=i;
    while (j<n)and(a[j+1]=a[i])do inc(j);
    k:=j-i+1;
    inc(res,k*(k+1)shr 1);
    i:=j+1;
  end;
  writeln(res);
end.