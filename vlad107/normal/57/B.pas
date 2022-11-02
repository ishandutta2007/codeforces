var
  res:int64;
  x,i,j,n,m,k:longint;
  l,r,u:array[0..1000000]of longint;
begin
  read(n,m,k);
  for i:=1 to m do 
    read(l[i],r[i],u[i]);
  res:=0;
  for i:=1 to k do begin
    read(x);
    for j:=1 to m do 
      if (x>=l[j])and(x<=r[j])then inc(res,u[j]+x-l[j]);
  end;
  writeln(res);
end.