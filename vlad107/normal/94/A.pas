var
  i,j:longint;
  q,s:ansistring;
  t:array[0..10]of ansistring;

begin
  readln(s);
  for i:=0 to 9 do readln(t[i]);
  for i:=1 to 8 do begin
    q:=copy(s,1,10);
    delete(s,1,10);
    j:=0;
    while (t[j]<>q)do inc(j);
    write(j);
  end;
  writeln;
end.