var
  s:ansistring;
  k4,k7,i:longint;

begin
  readln(s);
  k4:=0;k7:=0;
  for i:=1 to length(s) do
    if (s[i]='4')then inc(k4)else if (s[i]='7')then inc(k7);
  if (k4=0)and(k7=0)then writeln(-1)else if (k4>=k7)then writeln('4')else writeln('7');
end.