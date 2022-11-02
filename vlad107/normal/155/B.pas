uses
  math;

var
  f:array[0..1111,0..1111]of longint;
  i,j,n,tmp:longint;
  a,b:array[0..1111]of longint;

begin
  read(n);
  for i:=1 to n do read(a[i],b[i]);
  for i:=1 to n-1 do 
    for j:=1 to n-1 do 
      if (b[j]<b[j+1])or(b[j]=b[j+1])and(a[j]<a[j+1])then begin 
        tmp:=a[j];a[j]:=a[j+1];a[j+1]:=tmp;
        tmp:=b[j];b[j]:=b[j+1];b[j+1]:=tmp;
      end;
  fillchar(f,sizeof(f),$FF);      
  f[1][1]:=0;      
  for i:=1 to n do 
    for j:=0 to n do 
      if (f[i][j]<>-1)then begin
        f[i+1][j]:=max(f[i+1][j],f[i][j]);
        if (j>0)
          then f[i+1][min(j+b[i]-1,n)]:=max(f[i+1][min(j+b[i]-1,n)],f[i][j]+a[i]);
      end;
  for j:=1 to n do  
    if (f[n+1][j]>f[n+1][0])
      then f[n+1][0]:=f[n+1][j];
  writeln(f[n+1][0]);             
end.