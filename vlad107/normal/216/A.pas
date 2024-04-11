var
  a,b,c,res:longint;

begin
  read(a,b,c);
  while (a>1)or(b>1)or(c>1)do begin
    res:=res+2*(a+b+c-3);
    dec(a);dec(b);dec(c);
  end;
  writeln(res+a*b*c);
end.