var
  n,min,i,r1,r2,x:longint;
  
begin
  read(n);
  min:=1000000000;
  for i:=0 to n do begin
    x:=n-4*i;
    if (x<0)then continue;
    if (x mod 7<>0)then continue;
    x:=x div 7;
    if (i+x<min)then begin
      min:=i+x;
      r1:=i;r2:=x;
    end;
  end;
  if (min=1000000000)
    then writeln(-1)
    else begin
      for i:=1 to r1 do write(4);
      for i:=1 to r2 do write(7);
      writeln;
    end;
end.