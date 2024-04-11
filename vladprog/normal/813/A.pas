var
  n,m,i,s,a,l,r:longint;

begin
  read(n);
  s:=0;
  for i:=1 to n do
    begin
      read(a);
      inc(s,a)
    end;
  read(m);
  for i:=1 to m do
    begin
      read(l,r);
      if (l<=s)and(s<=r) then
        begin
          writeln(s);
          halt
        end;
      if l>s then
        begin
          writeln(l);
          halt
        end
    end;
  writeln(-1)
end.