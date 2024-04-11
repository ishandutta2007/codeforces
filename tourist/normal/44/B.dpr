{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,a,b,c,q,y,z,ans: longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n,a,b,c);
  n:=n*2; ans:=0;
  for y:=0 to b do
    for z:=0 to c do
    begin
      q:=n-2*y-4*z;
      if (q >= 0) and (q <= a) then inc(ans);
    end;
  writeln(ans);
  close(input);
  close(output);
end.