{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,m: longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,m);
  writeln(n*m div 2);
  close(input);
  close(output);
end.