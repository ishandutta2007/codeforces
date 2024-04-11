{$r-,q-,s-,i-,o+}
var
  res,d,n,x,i:longint;

begin
  read(d,n);
  res:=0;
  for i:=1 to n do begin
    read(x);
    if (i=n)then break;
    res:=res+(d-x);
  end;
  writeln(res);
end.