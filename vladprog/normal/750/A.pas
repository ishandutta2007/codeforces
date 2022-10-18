var
  n,k,i:longint;

begin
  read(n,k);
  k:=(240-k) div 5;
  for i:=1 to n do
    if i>k
      then
        begin
          writeln(i-1);
          exit
        end
      else dec(k,i);
  writeln(n)
end.