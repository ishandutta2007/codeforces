{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  x1,y1,z1,x2,y2,z2: longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(x1,y1,z1,x2,y2,z2);
  if (x1 = x2) or (y1 = y2) or (z1 = z2) then writeln('YES')
  else writeln('NO');
  close(input);
  close(output);
end.