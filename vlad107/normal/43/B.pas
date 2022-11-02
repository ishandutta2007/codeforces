var
  s:ansistring;
  a:array[0..1000]of longint;
  i:longint;

begin
  readln(s);
  for i:=1 to length(s)do inc(a[ord(s[i])]);
  readln(s);
  for i:=1 to length(s)do dec(a[ord(s[i])]);
  for i:=0 to 255 do 
    if (i<>32) and (a[i]<0)
      then begin
        writeln('NO');
        exit;
      end;
  writeln('YES');
end.