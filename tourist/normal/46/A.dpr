{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,i,x: longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  x:=1;
  for i:=1 to n-1 do
  begin
    x:=(x+i-1) mod n+1;
    write(x);
    if i < n-1 then write(' ');
  end;
  writeln;
  close(input);
  close(output);
end.