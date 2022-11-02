var
  res,i,j,n,d:longint;
  a:array[1..10000]of longint;

begin
  reaD(n,d);
  for i:=1 to n do read(a[i]);
  res:=0;
  for i:=1 to n do 
    for j:=1 to n do 
      if (i<>j)and(abs(a[i]-a[j])<=d)then inc(res);
  writeln(res);
end.