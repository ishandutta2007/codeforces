{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  a,b,x,y,c,d,ans,ka,kb,na,nb: int64;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(a,b,x,y);
  c:=x; d:=y;
  while (c > 0) and (d > 0) do
    if c > d then c:=c mod d
    else d:=d mod c;
  x:=x div (c+d);
  y:=y div (c+d);
  ans:=0; ka:=0; kb:=0;
  na:=a div x*x;
  nb:=a div x*y;
  if (na <= a) and (nb <= b) then
    if na*nb > ans then
    begin
      ans:=na*nb;
      ka:=na;
      kb:=nb;
    end;
  na:=b div y*x;
  nb:=b div y*y;
  if (na <= a) and (nb <= b) then
    if na*nb > ans then
    begin
      ka:=na;
      kb:=nb;
    end;
  writeln(ka,' ',kb);
  close(input);
  close(output);
end.