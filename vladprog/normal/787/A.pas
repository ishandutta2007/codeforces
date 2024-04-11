var
  a,b,c,d,i:longword;
  arr:array[1..10000]of boolean;

begin
  read(a,b,c,d);
  i:=b;
  while i<=10000 do
    begin
      arr[i]:=true;
      inc(i,a)
    end;
  i:=d;
  while i<=10000 do
    begin
      if arr[i] then
        begin
          writeln(i);
          halt
        end;
      inc(i,c)
    end;
  writeln(-1)
end.