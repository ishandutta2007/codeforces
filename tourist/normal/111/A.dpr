{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,x,y,s: int64;
  i: longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,x,y);
  if n > y then writeln(-1) else
  begin
    s:=n-1+(y-n+1)*(y-n+1);
    if s < x then writeln(-1) else
    begin
      for i:=1 to n-1 do writeln(1);
      writeln(y-n+1);
    end;
  end;
  close(input);
  close(output);
end.