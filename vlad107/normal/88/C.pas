var
  i,tt,tmp,a,b:longint;
  r1,r2,x:int64;
  res:array[1..5]of string;
  function gcd(a,b:longint):longint;
    begin
      while (a>0)and(b>0)do
        if (a>b)then a:=a mod b else b:=b mod a;
      gcd:=a+b;
    end;
begin
  res[1]:='Dasha';
  res[2]:='Masha';
  reaD(a,b);
  tt:=1;
  if (a>b)then begin
    tmp:=a;a:=b;b:=tmp;
    tt:=3-tt;
  end;
  if (b>2*a)then begin
    writeln(res[tt]);
    exit;
  end;
  if (b=2*a)then begin
    writeln('Equal');
    exit;
  end;
  x:=int64(a)*b div gcd(a,b);
  r2:=0;
  for i:=1 to x div b do r2:=r2+i*int64(b-a);
  r1:=x-r2;
  if (r1<r2)then writeln(res[tt])else
  if (r1>r2)then writeln(res[3-tt])else
  writeln('Equal');
end.