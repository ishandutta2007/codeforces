{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  a,b: longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(a,b);
  dec(a); dec(b);
  while (a > 0) and (b > 0) do
    if a > b then a:=a mod b
    else b:=b mod a;
  writeln(a+b+1);
  close(input);
  close(output);
end.