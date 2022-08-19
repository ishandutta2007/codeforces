{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  tt,qq,n: longint;
begin
  assign(input,'input.txt'); reset(input);
  assign(output,'output.txt'); rewrite(output);
  read(tt);
  for qq:=1 to tt do
  begin
    read(n);
    writeln(1-(n and 1));
  end;
  close(input);
  close(output);
end.