var
  a,b,c,x,y,z:longint;

begin
  read(x,y,z);
  b:=trunc(sqrt(x*y div z));
  a:=x div b;
  c:=y div b;
  writeln(4*(a+b+c));
end.