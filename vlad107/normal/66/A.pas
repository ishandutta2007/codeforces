var
  s:ansistring;
  i:longint;
  function cmp(a,b:ansistring):boolean;
    begin
      if (length(a)<>length(b))
        then cmp:=length(a)<length(b)
        else cmp:=a<=b;
    end;
begin
  readln(s);
  if (s='-0')then begin
    writeln('byte');
    exit;
  end;
  if (s[1]='-')then begin
    delete(s,1,1);
    i:=length(s);
    while (s[i]='0')do begin
      s[i]:='9';
      dec(i);
    end;
    s[i]:=chr(ord(s[i])-1);
  end;
  if (cmp(s,'127'))then writeln('byte')else
  if (cmp(s,'32767'))then writeln('short')else
  if (cmp(s,'2147483647'))then writeln('int')else
  if (cmp(s,'9223372036854775807'))then writeln('long')else
  writeln('BigInteger');
end.