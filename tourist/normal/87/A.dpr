{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
var
  x,sa,sb: int64;
  t,w,a,b: longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(a,b);
  x:=0; sa:=0; sb:=0;
  while True do
  begin
    t:=a-x mod a;
    w:=b-x mod b;
    if (t = a) and (w = b) and (x > 0) then break;
    if (t < w) or (t = w) and (a > b) then
    begin
      sa:=sa+t;
      x:=x+t;
    end else
    begin
      sb:=sb+w;
      x:=x+w;
    end;
  end;
  if sa = sb then writeln('Equal') else
  if sa > sb then writeln('Dasha')
  else writeln('Masha');
  close(input);
  close(output);
end.