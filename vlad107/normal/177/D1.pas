var
  n,m,base,i,ll,rr:longint;
  a,b,s1:array[0..500500]of longint;

begin
  read(n,m,base);
  for i:=1 to n do read(a[i]);
  for i:=1 to m do read(b[i]);
  s1[0]:=0;
  for i:=1 to m do s1[i]:=(s1[i-1]+b[i])mod base;
  for i:=1 to n do begin
    rr:=i;
    if (rr>m)then rr:=m;
    ll:=i-n+m;
    if (ll<1)then ll:=1;
    write((a[i]+s1[rr]-s1[ll-1]+base*1000)mod base,' ');
  end;
  writeln;
end.