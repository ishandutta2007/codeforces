{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,k,i,a,s: longint;
begin
  assign(input,'input.txt'); reset(input);
  assign(output,'output.txt'); rewrite(output);
  read(n,k);
  s:=0;
  for i:=1 to n do
  begin
    read(a);
    if a > 3*k then s:=s+a-3*k
    else s:=s+a mod k;
  end;
  writeln(s);
  close(input);
  close(output);
end.