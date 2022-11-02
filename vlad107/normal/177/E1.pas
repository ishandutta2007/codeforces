{$r-,q-,s-,i-,o+}
var
  sum,x,ans,i,n,c:longint;
  a,b:array[0..500500]of longint;

begin
  read(n,c);
  for i:=1 to n do read(a[i],b[i]);
  ans:=0;
  for x:=1 to 100000 do begin
    sum:=0;
    for i:=1 to n do sum:=sum+1+(int64(a[i])*x div b[i]);
    if (sum=c)then inc(ans);
  end;
  writeln(ans);
end.