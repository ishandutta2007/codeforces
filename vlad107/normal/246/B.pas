const
  maxn=10000;

var
  x1,x2,tt,i,j,n,x:longint;
  a:array[0..500500]of longint;

begin
  read(n);
  j:=0;
  for i:=1 to n do begin
    read(x);
    inc(j,x);
  end;
  if (j mod n=0)then writeln(n)else writeln(n-1);
end.