var
  y,k,n,i:longint;

begin
  read(y,k,n);
  if ((n div k)*k<=y)then begin
    writeln(-1);
    exit;
  end;
  for i:=1 to n div k do
    if ((i*k)>y)then write(i*k-y,' ');
end.