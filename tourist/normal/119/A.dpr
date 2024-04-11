{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  a,b,n: longint;

function gcd(a,b:longint):longint;
begin
  while (a > 0) and (b > 0) do
    if a > b then a:=a mod b
    else b:=b mod a;
  gcd:=a+b;
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(a,b,n);
  while n > 0 do
  begin
    if gcd(a,n) = n then
    begin
      writeln(0);
      break;
    end;
    n:=n-gcd(a,n);
    if gcd(b,n) = n then
    begin
      writeln(1);
      break;
    end;
    n:=n-gcd(b,n);
  end;
  close(input);
  close(output);
end.