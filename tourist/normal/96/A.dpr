{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  s: ansistring;
  i: longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  readln(s);
  for i:=1 to length(s)-6 do
    if (s[i] = s[i+1]) and (s[i] = s[i+2]) and (s[i] = s[i+3]) and (s[i] = s[i+4]) and (s[i] = s[i+5]) and (s[i] = s[i+6]) then
    begin
      writeln('YES');
      halt;
    end;
  writeln('NO');
  close(input);
  close(output);
end.