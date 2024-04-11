var
  k,d,i:longint;

begin
  read(k,d);
  if (k<>1)and(d=0)
    then writeln('No solution')
    else
      begin
        write(d);
        for i:=1 to k-1 do
          write('0')
      end
end.