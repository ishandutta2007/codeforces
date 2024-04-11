var
  t,i,j,n,r:longint;

begin
  read(t);
  for i:=1 to t do
    begin
      read(n,r);
      t:=r mod n;
      for j:=1 to n-1 do
        begin
          read(r);
          t:=(t+r) mod n
        end;
      writeln(n-t)
    end
end.