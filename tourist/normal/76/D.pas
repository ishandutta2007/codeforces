{$R-,S-,Q-,I-,O+}
var
  a,b,x,y: qword;
begin
  read(a,b);
  if (a < b) or ((a-b) and 1 = 1) then writeln(-1) else
  begin
    x:=(a-b) shr 1;
    y:=a-x;
    if x xor y = b then writeln(x,' ',y)
    else writeln(-1);
  end;
end.