var a,b:longint;
begin
  readln(a,b);
  if (abs(a-b)<=1) and not((a=0) and (b=0)) then writeln('YES') else writeln('NO');
end.