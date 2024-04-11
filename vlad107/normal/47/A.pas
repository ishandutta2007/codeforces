var
  t,i:longint;

begin
  read(t);
  for i:=1 to 1000 do 
    if (i*(i+1)=t*2)then begin
      writeln('YES');
      exit;
    end;
  writeln('NO');
end.