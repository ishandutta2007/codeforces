const
  eps=1e-10;
var
  k1,k2,ll,rr,x:extended;
  j,m1,m2,n,k,i:longint;
  a:array[0..100500]of longint;
  procedure qs(l,r:longint);
    var
      i,j,xx,tmp:longint;
    begin
      i:=l;j:=r;
      xx:=a[(i+j)shr 1];
      while (i<=j)do begin
        while (xx>a[i])do inc(i);
        while (xx<a[j])do dec(j);
        if (i>j)then break;
        tmp:=a[i];a[i]:=a[j];a[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<r)then qs(i,r);
      if (j>l)then qs(l,j);
    end;
begin
  read(n,k);
  for i:=1 to n do read(a[i]);
  qs(1,n);
  ll:=0;rr:=1e9;
  while (rr-ll>eps)do begin
    x:=(ll+rr)/2;
    k1:=0;k2:=0;
    for i:=1 to n do
      if (a[i]-x<0)then k2:=k2-a[i]+x else k1:=k1+a[i]-x;
    if (k1-k1*k/100>k2)then ll:=x else rr:=x;
  end;
  writeln(ll:0:7);
end.