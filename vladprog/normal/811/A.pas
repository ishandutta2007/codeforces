{$macro+}
{ $define free}

var
  a,b,i:longint;

begin
  read(a,b);
  i:=0;
  repeat
    inc(i);
    if i>a
      then
        begin
          writeln('Vladik');
          halt
        end
      else dec(a,i);
    inc(i);
    if i>b
      then
        begin
          writeln('Valera');
          halt
        end
      else dec(b,i)
  until false
end.