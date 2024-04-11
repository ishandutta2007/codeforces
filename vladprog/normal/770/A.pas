var
  n,k,i:longint;

begin
  read(n,k);
  for i:=0 to n-1 do
    write(chr(ord('a')+i mod k))
end.