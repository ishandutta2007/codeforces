{$r-,q-,s-,i-,o+}
const
  maxn=15000000;
  maxp=5000;

var
  g,f:array[0..maxn]of longint;
  prime:array[0..maxp]of boolean;
  a,n,i,j,x:longint;
  ans:int64;
  

begin
  read(a,n);
  fillchar(prime,sizeof(prime),true);
  prime[1]:=false;
  for i:=2 to maxp do 
    if (prime[i])then begin
      for j:=2 to maxp div i do prime[i*j]:=false;
      x:=i*i;
      for j:=1 to maxn div x do 
        if (g[x*j]=0)then g[x*j]:=x;
    end;
  for i:=1 to a+n-1 do 
    if (g[i]=0)
      then f[i]:=i
      else f[i]:=f[i div g[i]];
  ans:=0;
  for i:=a to a+n-1 do ans:=ans+f[i];
  writeln(ans);
end.