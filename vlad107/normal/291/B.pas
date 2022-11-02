var
  z,s:ansistring;
  f:boolean;
  i:longint;

begin
  readln(s);
  z:='';f:=false;
  for i:=1 to length(s)do
    if (s[i]='"')then begin
      if (f)then writeln('<',z,'>');
      f:=f xor true;
      z:='';
    end else
    if (s[i]=' ')and(not f)then begin
      if (z<>'')then writeln('<',z,'>');
      z:='';
    end else z:=z+s[i];
  if (z<>'')then writeln('<',z,'>');
end.