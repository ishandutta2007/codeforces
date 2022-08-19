{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  a: string;
  b: longint;
begin
  assign(input,'input.txt'); reset(input);
  assign(output,'output.txt'); rewrite(output);
  readln(a);
  read(b);
  if (a[1] = 'f') and (b = 1) or (a[1] = 'b') and (b = 2) then writeln('L')
  else writeln('R');
  close(input);
  close(output);
end.