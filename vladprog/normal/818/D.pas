var
  n,a,c,i:longint;
  cnt:array[1..1000000]of longint;

begin
  read(n,a);
  for i:=1 to n do
    begin
      read(c);
      if cnt[c]<cnt[a]
        then cnt[c]:=-1
        else inc(cnt[c]);
    end;
  for c:=1 to 1000000 do
    if(c<>a)and(cnt[c]>=cnt[a]) then
      begin
        writeln(c);
        halt
      end;
  writeln(-1)
end.