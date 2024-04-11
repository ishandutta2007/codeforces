{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  tt,qq,n: longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(tt);
  for qq:=1 to tt do
  begin
    read(n);
    if n = 1 then writeln(0)
    else writeln(n-2);
  end;
  close(input);
  close(output);
end.