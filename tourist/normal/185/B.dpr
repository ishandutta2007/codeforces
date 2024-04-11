{$R-,S-,Q-,I-,O+}
var
  s,a,b,c: longint;
begin
  read(s,a,b,c);
  if a+b+c = 0 then writeln(s,' 0 0')
  else writeln(a*s/(a+b+c):0:17,' ',b*s/(a+b+c):0:17,' ',c*s/(a+b+c):0:17);
end.