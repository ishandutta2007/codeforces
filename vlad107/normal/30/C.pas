var
  t2,res:extended;
  p,f:array[0..100500]of extended;
  tmp,i,j,n:longint;
  t,x,y:array[0..100500]of longint;

begin
  read(n);
  for i:=1 to n do read(x[i],y[i],t[i],p[i]);
  for i:=1 to n-1 do
    for j:=1 to n-1 do 
      if (t[j]>t[j+1])then begin
        tmp:=x[j];x[j]:=x[j+1];x[j+1]:=tmp;
        tmp:=y[j];y[j]:=y[j+1];y[j+1]:=tmp;
        tmp:=t[j];t[j]:=t[j+1];t[j+1]:=tmp;
        t2:=p[j];p[j]:=p[j+1];p[j+1]:=t2;
      end;
  for i:=1 to n do f[i]:=p[i];
  for i:=2 to n do 
    for j:=1 to i-1 do 
      if ((x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i])<=int64(t[i]-t[j])*(t[i]-t[j]))and(f[j]+p[i]>f[i])
        then f[i]:=f[j]+p[i];
  res:=0;
  for i:=1 to n do
    if (f[i]>res)then res:=f[i];
  writeln(res:0:10);
end.