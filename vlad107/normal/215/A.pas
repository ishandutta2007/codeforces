var
  max,res,n,m,i,j:longint;
  a,b:array[0..500500]of longint;

begin
  read(n);
  for i:=1 to n do read(a[i]);
  read(m);
  for i:=1 to m do read(b[i]);
  for i:=1 to n do 
    for j:=1 to m do 
      if (b[j] mod a[i]=0)and(b[j] div a[i]>max)then max:=b[j] div a[i];
  for i:=1 to n do 
    for j:=1 to m do 
        if (b[j] mod a[i]=0)and(b[j] div a[i]=max)then inc(res);
  writeln(res);
end.