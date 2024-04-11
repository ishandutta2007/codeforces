{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  x,y,z,k: int64;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(x,y,z,k);
  inc(k,3);
  while x+y+z > k do
    if (x > y) and (x > z) then dec(x) else
    if y > z then dec(y)
    else dec(z);
  writeln(x*y*z);
  close(input);
  close(output);
end.