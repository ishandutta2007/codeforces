{$R-,S-,Q-,I-,O+}
var
  n,i: longint;
  p,s,sq: array [0..200010] of extended;
begin  
  read(n);
  for i:=1 to n do read(p[i]);
  sq[0]:=0; s[0]:=0;
  for i:=1 to n do
  begin
    s[i]:=(s[i-1]+1)*p[i];
    sq[i]:=sq[i-1]+(2*s[i-1]+1)*p[i];
  end;
  writeln(sq[n]:0:17);
end.