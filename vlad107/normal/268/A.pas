var
  res,n,i,j:longint;
  a,b:array[0..500500]of longint;

begin
  read(n);
  for i:=1 to n do read(a[i],b[i]);
  res:=0;
  for i:=1 to n do
    for j:=1 to n do
      if (i<>j)and(b[i]=a[j])then inc(res);
  writeln(res);
end.