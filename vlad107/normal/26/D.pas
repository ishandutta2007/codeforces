var
  res:extended;
  n,m,k,i:longint;

begin
  read(n,m,k);
  if (k+n-m<0)then res:=0 else
  if (k-m>=0)then res:=1 else begin
    res:=1;
    for i:=0 to k do res:=res*(m-k+i)/(n+1+i);
    res:=1-res;
  end;
  writeln(res:0:10);
end.