{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  x,y,d,u: longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(x,y);
  d:=x*x+y*y;
  u:=round(sqrt(d));
  if u*u = d then writeln('black') else
  begin
    if u*u > d then dec(u);
    if x < 0 then inc(u);
    if y < 0 then inc(u);
    if u and 1 = 1 then writeln('white')
    else writeln('black');
  end;
  close(input);
  close(output);
end.