{$r-,q-,s-,i-,o+}
var
  tt,n,k,i,j,res:longint;
  a,b:array[0..500500]of longint;
  f:array[0..4444,0..4444]of longint;

begin
  read(n,k);
  for i:=1 to n do read(a[i],b[i]);
  fillchar(f,sizeof(f),$FF);
  f[1][0]:=0;
  for i:=1 to n do 
    for j:=0 to k do 
      if (f[i][j]<>-1)then begin
        if (j<k)and((f[i][j+1]<0)or(f[i][j]<f[i][j+1]))then f[i][j+1]:=f[i][j];
        if (j<k)and((f[i+1][j+1]<0)or(f[i][j]<f[i+1][j+1]))
          then f[i+1][j+1]:=f[i][j];
        tt:=a[i]+b[i]-1;
        if (a[i]<=f[i][j])then tt:=f[i][j]+b[i];
        if ((f[i+1][j]<0)or(tt<f[i+1][j]))
          then f[i+1][j]:=tt;
      end;
  for j:=0 to k-1 do 
    if (f[n+1][j+1]<0)or(f[n+1][j]<f[n+1][j+1])
      then f[n+1][j+1]:=f[n+1][j];
  a[n+1]:=86401;
  for i:=1 to n+1 do 
    if (a[i]-f[i][k]-1>res)then res:=a[i]-f[i][k]-1;
  writeln(res);
end.