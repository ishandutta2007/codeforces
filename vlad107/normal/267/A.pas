var
  res,tt,a,b:longint;

begin
  read(tt);
  while (tt>0)do begin
    dec(tt);
    read(a,b);
    res:=0;
    while (a<>0)and(b<>0)do
      if (a>b)then begin
        res:=res+(a div b);
        a:=a mod b;
      end else begin
        res:=res+(b div a);
        b:=b mod a;
      end;
    writeln(res);
  end;
end.