{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  a,b: ansistring;
  n,i,x,y: longint;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  readln(a);
  readln(b);
  n:=length(a);
  x:=0; y:=0;
  for i:=1 to n do
    if a[i] < b[i] then inc(x) else
    if a[i] > b[i] then inc(y);
  if x > y then writeln(x)
  else writeln(y);
  close(input);
  close(output);
end.