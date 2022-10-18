var
  n,a,b,c,i,k:longint;

begin
  read(n);
  k:=0;
  for i:=1 to n do
    begin
      read(a,b,c);
      if a+b+c>=2 then inc(k)
    end;
  writeln(k)
end.