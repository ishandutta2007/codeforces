{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  f,n,i,s,x,a,b: longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  s:=0;
  for i:=2 to n-1 do
  begin
    x:=n;
    while x > 0 do
    begin
      inc(s,x mod i);
      x:=x div i;
    end;
  end;
  f:=n-2;
  a:=s; b:=f;
  while (a > 0) and (b > 0) do
    if a > b then a:=a mod b
    else b:=b mod a;
  writeln(s div (a+b),'/',f div (a+b));
  close(input);
  close(output);
end.