{$R-,S-,Q-,I-,O+}
const md = 1000000009;
var
  n,f,p,t: int64;
begin
  read(n);
  f:=1; p:=2; t:=4;
  while n > 2 do
  begin
    t:=(t*f) mod md;
    p:=(p+t) mod md;
    f:=(f*2+3) mod md;
    dec(n,2);
  end;
  writeln((p*p+1)*2 mod md);
end.