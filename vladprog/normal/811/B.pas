const
  maxn=10000;

var
  n,m,i,j,l,r,x,k:longint;
  p:array[1..maxn]of longint;

begin
  read(n,m);
  for i:=1 to n do
    read(p[i]);
  for i:=1 to m do
    begin
      read(l,r,x);
      k:=0;
      for j:=l to r do
        if p[j]<p[x]
          then inc(k);
      if k=x-l
        then writeln('Yes')
        else writeln('No')
    end
end.