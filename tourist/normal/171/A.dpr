{$R+,S+,Q+,I+,O-}
var
  x,y,z: int64;
  i: longint;
  s: ansistring;
begin
  read(x,y);
  str(y,s);
  z:=0;
  for i:=length(s) downto 1 do z:=z*10+Ord(s[i])-48;
  writeln(x+z);
end.