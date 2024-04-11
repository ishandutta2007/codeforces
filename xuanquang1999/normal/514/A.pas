var s: string;
    i: longint;
begin
 readln(s);
 for i:=1 to length(s) do
  if ((i > 1) or (s[1] <> '9')) and (s[i] > '4') then s[i]:=chr(48+57-ord(s[i]));
 writeln(s);
end.