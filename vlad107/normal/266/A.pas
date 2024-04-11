var
  i,res:longint;
  s:ansistring;

begin
  readln(res);
  readln(s);
  res:=0;
  for i:=2 to length(s)do if (s[i]=s[i-1])then inc(res);
  writeln(res);
end.