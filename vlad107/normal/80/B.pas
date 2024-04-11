var
  a,b:longint;
  c:char;
begin
  a:=0;
  read(c);a:=a*10+ord(c)-48;
  read(c);a:=a*10+ord(c)-48;
  read(c);
  b:=0;
  read(c);b:=b*10+ord(c)-48;
  read(c);b:=b*10+ord(c)-48;
  a:=a mod 12;
  writeln(a*30+b/2:0:1,' ',b*6);
end.