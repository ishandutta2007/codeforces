var
  res,n,i,cr,a,b:longint;

begin
  read(n);
  res:=n;
  for i:=1 to n-1 do begin
    cr:=0;
    a:=n;
    b:=i;
    while (a<>0)and(b<>0)do
      if (a>b)then begin
        inc(cr,a div b);
        a:=a mod b;
      end else begin
        inc(cr,b div a);
        b:=b mod a;
      end;
    if (a+b<>1)then continue;
    if (cr<res)then res:=cr;
  end;
  writeln(res-1);                 
end.