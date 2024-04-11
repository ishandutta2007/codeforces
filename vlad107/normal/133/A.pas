var
  s:ansistring;

begin
  readln(s);
  if (pos('H',s)>0)or(pos('Q',s)>0)or(pos('9',s)>0)
    then writeln('YES')
    else writeln('NO');
end.