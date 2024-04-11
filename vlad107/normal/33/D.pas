var
  a,b,res,n,m,k,i,j:longint;
  x,y,r,x0,y0:array[0..1005000]of longint;
  w:array[0..1111,0..1111]of boolean;

begin
  read(n,m,k);
  for i:=1 to n do read(x[i],y[i]);
  for i:=1 to m do read(r[i],x0[i],y0[i]);
  for i:=1 to n do 
    for j:=1 to m do 
      if (int64(x[i]-x0[j])*(x[i]-x0[j])+int64(y[i]-y0[j])*(y[i]-y0[j])<=int64(r[j])*r[j])
        then w[i][j]:=true else w[i][j]:=false;
  for i:=1 to k do begin
    read(a,b);
    res:=0;
    for j:=1 to m do 
      if (w[a][j]xor w[b][j])then inc(res);
    writeln(res);
  end;
end.