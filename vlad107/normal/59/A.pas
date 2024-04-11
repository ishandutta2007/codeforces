var
  s:string;
  i,k:longint;

begin
  readln(s);
  k:=0;
  for i:=1 to length(s)do 
    if (s[i]>='A')and(s[i]<='Z')
      then inc(k);
  if (k>length(s)-k)
    then for i:=1 to length(s)do s[i]:=upcase(s[i])
    else for i:=1 to length(s)do if (s[i]>='A')and(s[i]<='Z')then s[i]:=chr(ord(s[i])+32);
  writeln(s);
end.