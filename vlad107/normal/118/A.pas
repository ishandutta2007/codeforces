var
  s,p:ansistring;
  i:longint;

begin
  readln(s);
  for i:=1 to length(s)do 
    if not ((s[i]in['A','O','Y','E','U','I'])or
       (upcase(s[i])in['A','O','Y','E','U','I']))
         then p:=p+'.'+s[i];
  for i:=1 to length(p)do if (p[i]<>'.')then p[i]:=chr(ord(upcase(p[i]))+32);
  writeln(p);
end.