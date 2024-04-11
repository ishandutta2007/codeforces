{$r-,q-,s-,i-,o+}
var
  mid,ll,rr,n,i:longint;
  a,f:array[0..500500]of longint;

begin
  read(n);
  for i:=1 to n do read(a[i]);
  f[n+1]:=1000000001;
  for i:=n downto 1 do begin
    f[i]:=f[i+1];
    if (a[i]<f[i])then f[i]:=a[i];
  end;
  for i:=1 to n do begin
    if (i=n)or(f[i+1]>=a[i])then begin
      write(-1,' ');
      continue;
    end;
    ll:=i+1;
    rr:=n;
    while (ll<rr-1)do begin
      mid:=(ll+rr)shr 1;
      if (f[mid]<a[i])then ll:=mid else rr:=mid;
    end;
    if (a[rr]<a[i])
      then write(rr-i-1,' ')
      else
    if (a[ll]<a[i])
      then write(ll-i-1,' ')
      else write(-1,' ');
  end;
end.