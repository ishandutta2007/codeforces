{$R-,S-,Q-,I-,O+}
var
  t,a,b,p: int64;

procedure get(b:int64);
begin
  while b and 3 <> 3 do
  begin
    p:=p xor b;
    dec(b);
  end;
end;

begin
  read(t);
  p:=0;
  while t > 0 do
  begin
    dec(t);
    read(a,b);
    get(a+b-1);
    get(a-1);
  end;
  if p = 0 then writeln('bolik')
  else writeln('tolik');
end.