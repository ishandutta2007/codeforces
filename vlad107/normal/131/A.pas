var
  s:ansistring;
  i:longint;

begin
  readln(s);
  i:=length(s);
  while (i>0)and(s[i] in ['A'..'Z'])do dec(i);
  if (i<2)then begin
    for i:=1 to length(s)do
      if (s[i]in['A'..'Z'])
        then s[i]:=chr(ord(s[i])+32)
        else s[i]:=chr(ord(s[i])-32);
  end;
  writeln(s);
end.