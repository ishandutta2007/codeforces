{$r-,q-,s-,i-,o+}
var
  res:int64;
  mm,x,n,m,k,i:longint;
  a:array[0..100500]of longint;

begin
  read(n,m,k);
  for i:=1 to n do read(a[i]);
  if (m<(n+1)div 2)or(n mod 2=0)then begin
    writeln(0);
    exit;
  end;
  if (n=1)then begin
    res:=int64(m)*k;
    if (a[1]<res)then res:=a[1];
    writeln(res);
    exit;
  end;
  res:=(n+1) div 2;
  res:=m div res;
  res:=res*k;
  for i:=1 to n do 
    if (i and 1=1)and(a[i]<res)then res:=a[i];
  writeln(res);
end.