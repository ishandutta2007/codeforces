{$r-,q-,s-,i-,o+}
var
  d,n,a,b,x:longint;
  function gcd(a,b:longint):longint;
    begin
      while (a>0)and(b>0)do
        if (a>b)then a:=a mod b else b:=b mod a;
      gcd:=a+b;
    end;

begin
  read(a,b,n);
  x:=1;
  while (n>0)do begin
    if (x=1)then d:=gcd(a,n) else d:=gcd(b,n);
    dec(n,d);
    x:=3-x;
  end;
  if (x=2)then writeln(0)else writeln(1);
end.