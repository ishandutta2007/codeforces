var
  a,b,bb:longint;

begin
  read(a,b);
  bb:=0;
  while (b>0)do begin
    bb:=bb*10+b mod 10;
    b:=b div 10;
  end;
  writeln(a+bb);
end.