{$r-,q-,s-,i-,o+}
var
  res,c:extended;
  n,m,x,i,sum:longint;
  a:array[0..500500]of longint;

begin
  read(n,m,x);
  sum:=0;
  for i:=1 to m do begin
    read(a[i]);
    sum:=sum+a[i];    
  end;
  if (sum<n)then begin
    writeln(-1);
    exit;
  end;
  dec(a[x]);
  dec(sum);
  res:=0;
  c:=1;
  for i:=2 to n do begin
    res:=res+c*a[x]/sum;
    c:=c*(sum-a[x])/sum;
    dec(sum);
  end;
  writeln(res:0:10);
end.