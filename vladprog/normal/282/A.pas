var
  n,x,i:longint;
  s:string;

begin
  readln(n);
  x:=0;
  for i:=1 to n do
    begin
      readln(s);
      if s[2]='+'
        then inc(x)
        else dec(x)
    end;
  writeln(x)
end.