{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  a,b,x,y: longint;

function check(a,b:longint):boolean;
begin
  if (b < a-1) or (b > (a+1)*2) then check:=False
  else check:=True;
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(a,b,x,y);
  if check(b,x) or check(a,y) then writeln('YES')
  else writeln('NO');
  close(input);
  close(output);
end.