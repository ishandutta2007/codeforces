{$R-,S-,Q-,I-,O+}
uses Math;
var
  n,r1,r2: longint;
  sn,ang: extended;
begin
{  assign(input,'in'); reset(input);
  assign(output,'out'); rewrite(output);}
  read(n,r1,r2);
  if r1 < r2 then writeln('NO') else
  if n = 1 then writeln('YES') else
  if 2*r2 > r1 then writeln('NO') else
  begin
    sn:=r2/(r1-r2);
    if sn > 1 then ang:=pi/2
    else ang:=arcsin(sn);
    ang:=ang*n;
    if ang > pi+1e-10 then writeln('NO')
    else writeln('YES');
  end;
{  close(input);
  close(output);}
end.