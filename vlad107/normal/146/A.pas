var
  n,b,i:longint;
  s:ansistring;

begin
  readln(n);
  readln(s);
  b:=0;
  for i:=1 to n do begin
    if (s[i]<>'4')and(s[i]<>'7')then begin
      writeln('NO');
      exit;
    end;
    if (i+i>n)then dec(b,ord(s[i])-48)else inc(b,ord(s[i])-48);
  end;
  if (b<>0)then writeln('NO')else writeln('YES');
end.