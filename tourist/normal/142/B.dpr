{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,m,c,x,y: longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,m);
  if n = 1 then writeln(m) else
  if m = 1 then writeln(n) else
  if (n > 2) and (m > 2) then writeln((n*m+1) div 2) else
  begin
    c:=n+m-2;
    x:=c div 2;
    y:=c-x;
    writeln((x+1) div 2*2+(y+1) div 2*2);
  end;
  close(input);
  close(output);
end.