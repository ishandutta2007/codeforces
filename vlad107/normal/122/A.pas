var
  n,i,x:longint;
  
begin
  read(n);
  for i:=4 to n do begin
    x:=i;
    while (x>0)do begin
      if (x mod 10<>4)and(x mod 10<>7)then break;
      x:=x div 10;
    end;
    if (x=0)and(n mod i=0)then begin
      writeln('YES');exit;
    end; 
  end;
  writeln('NO');
end.