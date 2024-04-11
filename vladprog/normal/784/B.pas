var
  n,res:longint;

begin
  read(n);
  res:=0;
  repeat
    case n mod 16 of
      0,4,6,9,10,13:inc(res);
      8,11:inc(res,2)
    end;
    n:=n div 16
  until n=0;
  writeln(res)
end.