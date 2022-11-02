uses
  math;
  
const 
  inf=1000000000;

var
  maxsum,n,i,x,j:longint;
  f,a:array[0..500500]of longint;

begin
  read(n);
  maxsum:=0;
  for i:=1 to n do read(a[i]);
  for i:=1 to n do inc(maxsum,a[i]);
  for i:=1 to maxsum do f[i]:=inf;
  f[0]:=0;
  for i:=1 to n do 
    for j:=maxsum-a[i] downto 0 do 
      f[j+a[i]]:=min(f[j+a[i]],f[j]+1);
  if (maxsum and 1=0)then x:=(maxsum+2)shr 1 else x:=(maxsum+1)shr 1;
  for i:=x+1 to maxsum do 
    if (f[i]<f[x])then f[x]:=f[i];
  writeln(f[x]);
end.