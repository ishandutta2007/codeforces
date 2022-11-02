var
  i,ll,rr,n,m,x,y:longint;
  a:array[0..500500]of longint;

begin
  read(n,m);
  for i:=1 to n do begin
    read(x,y);
    a[i]:=a[i-1]+x*y;
  end;
  for i:=1 to m do begin
    read(x);
    ll:=0;rr:=n-1;
    while (ll<rr-1)do
      if (a[(ll+rr)shr 1]<x)then ll:=(ll+rr)shr 1 else rr:=(ll+rr)shr 1;
    if (a[rr]<x)then writeln(rr+1)else 
    if (a[ll]<x)then writeln(ll+1);
  end;
end.