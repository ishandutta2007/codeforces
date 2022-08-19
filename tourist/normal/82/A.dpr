{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
const name: array [1..5] of string = ('Sheldon','Leonard','Penny','Rajesh','Howard');
var
  n,s,i: longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  s:=1;
  while n > 0 do
  begin
    for i:=1 to 5 do
    begin
      dec(n,s);
      if n <= 0 then
      begin
        writeln(name[i]);
        halt;
      end;
    end;
    s:=s shl 1;
  end;
  close(input);
  close(output);
end.