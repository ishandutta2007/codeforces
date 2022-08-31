{$APPTYPE CONSOLE}
var
  a,b,c: longint;
begin
  read(a,b,c);
  writeln(a*b+a*c+b*c-a-b-c+1);
end.