const
  base=1000000007;

var
  i,n,m,k,res:longint;

begin
  read(n,m,k);
  if (k>n)or(k=1)then begin
    res:=1;
    for i:=1 to n do res:=int64(res)*m mod base;
    writeln(res);
    exit;
  end;
  if (k=n)then begin
    res:=1;
    for i:=1 to (n+1) shr 1 do res:=int64(res)*m mod base;
    writeln(res);
    exit;
  end;
  if (k and 1=0)
    then writeln(m)
    else writeln(m*m);
end.