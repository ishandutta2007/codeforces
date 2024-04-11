var
  b,c,x,n,i,k:longint;

begin
  read(i,b,c,n);
  for i:=1 to n do
    begin
      read(x);
      if (x>b)and(x<c)
        then inc(k)
    end;
  writeln(k)
end.