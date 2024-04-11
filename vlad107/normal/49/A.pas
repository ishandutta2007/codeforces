var
  s:ansistring;
  i:longint;
  ok:boolean;

begin
  readln(s);
  ok:=false;
  for i:=1 to length(s) do 
    if (s[i] in ['A'..'Z','a'..'z'])then begin
      if (s[i]in['A','E','I','O','U','Y','a','e','i','o','u','y'])
        then ok:=true else ok:=false;
    end;
  if (ok)then writeln('YES') else writeln('NO');
end.