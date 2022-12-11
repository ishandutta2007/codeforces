var n,x,y,z:longint;
begin
  readln(n);
  x:=n;
  y:=n+1;
  z:=n*(n+1);
  if (n<>1) then writeln(x,' ',y,' ',z) else writeln('-1');
end.