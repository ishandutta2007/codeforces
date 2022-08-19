{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  a1,b1,c1,a2,b2,c2,d: longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(a1,b1,c1,a2,b2,c2);
  d:=a1*b2-a2*b1;
  if (a1 = 0) and (b1 = 0) and (c1 <> 0) then writeln(0) else
  if (a2 = 0) and (b2 = 0) and (c2 <> 0) then writeln(0) else
  if d = 0 then
  begin
    if a1*c2-c1*a2 = 0 then writeln(-1)
    else writeln(0);
  end
  else writeln(1);
  close(input);
  close(output);
end.