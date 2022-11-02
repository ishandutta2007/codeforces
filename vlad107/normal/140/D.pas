var
  cr,j,tmp,q,sq,res,n,i,t1,t2:longint;
  a:array[0..500500]of longint;
  f:array[0..111,0..722,0..722]of longint;

begin
  read(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n-1 do
    for j:=1 to n-1 do
      if (a[j]>a[j+1])then begin
        tmp:=a[j];a[j]:=a[j+1];a[j+1]:=tmp;
      end;

  q:=0;
  sq:=10;
  while (q<n)and(sq+a[q+1]<=720)do begin
    inc(q);
    inc(sq,a[q]);
  end;
  n:=q;
  write(n,' ');

  fillchar(f,sizeof(f),$FF);
  f[1][10][sq]:=0;
  for i:=1 to n do
    for t1:=10 to sq do
      for t2:=sq downto t1 do begin
        if (f[i][t1][t2]=-1)then continue;
        cr:=f[i][t1][t2];
        if (t1+a[i]>360)then cr:=cr+t1+a[i]-360;
        if (f[i+1][t1+a[i]][t2]=-1)or(cr<f[i+1][t1+a[i]][t2])then f[i+1][t1+a[i]][t2]:=cr;
        cr:=f[i][t1][t2];
        if (t2>360)then cr:=cr+t2-360;
        if (f[i+1][t1][t2-a[i]]=-1)or(cr<f[i+1][t1][t2-a[i]])then f[i+1][t1][t2-a[i]]:=cr;
      end;
  res:=1000000000;
  for t1:=0 to 720 do
    if (f[n+1][t1][t1]<>-1)and(f[n+1][t1][t1]<res)then res:=f[n+1][t1][t1];
  writeln(res);
end.