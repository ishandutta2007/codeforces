var
  i,j:longint;
  s,p:ansistring;
begin
  readln(s);
  p:='hello';
  j:=1;
  for i:=1 to length(s)do
    if (j<=length(p))and(s[i]=p[j])then inc(j);
  if (j>5)then writeln('YES')else writeln('NO');
end.