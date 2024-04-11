var
  i,j:longint;
  s,t:ansistring;

begin
  readln(s);
  readln(t);
  i:=1;
  for j:=1 to length(t)do
    if (t[j]=s[i])then inc(i);
  writeln(i);
end.