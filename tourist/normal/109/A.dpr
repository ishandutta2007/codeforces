{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
var
  i,n,x,d: longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  for d:=1 to n do
  begin
    x:=7*d-n;
    if x mod 3 <> 0 then continue;
    x:=x div 3;
    if (x >= 0) and (x <= d) then
    begin
      for i:=1 to x do write(4);
      for i:=x+1 to d do write(7);
      writeln;
      halt;
    end;
  end;
  writeln(-1);
  close(input);
  close(output);
end.