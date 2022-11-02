var
  s:ansistring;
  used:array['a'..'z']of boolean;
  kol,i:longint;
  
begin
  readln(s);
  for i:=1 to length(s)do begin
    if (used[s[i]])then continue;
    inc(kol);
    used[s[i]]:=true;
  end;
  if (kol and 1=1)
      then writeln('IGNORE HIM!')
      else writeln('CHAT WITH HER!');
end.