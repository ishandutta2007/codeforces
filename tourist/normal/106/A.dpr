{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
const let: string = '6789TJQKA';
var
  i,q,w: longint;
  c: array [0..6] of char;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  for i:=1 to 5 do
  begin
    read(c[i]);
    while not (c[i] in ['0'..'9','A'..'Z']) do read(c[i]);
  end;
  q:=Pos(c[2],let);
  w:=Pos(c[4],let);
  if (c[3] = c[1]) and (c[5] <> c[1]) then writeln('YES') else
  if (c[3] <> c[1]) and (c[5] = c[1]) then writeln('NO') else
  if (q > w) and (c[3] = c[5]) then writeln('YES')
  else writeln('NO');
  close(input);
  close(output);
end.