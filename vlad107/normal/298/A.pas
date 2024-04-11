var
  i:longint;
  s:ansistring;

begin
  readln(i);
  readln(s);
  for i:=1 to length(s)-1 do
    if (s[i]='R')and(s[i+1]='L')then begin
      writeln(i,' ',i+1);
      exit;
    end;
  for i:=1 to length(s)-1 do 
    if (s[i]='.')and(s[i+1]='L')then begin
      writeln(i+1,' ',i);
      exit;
    end;
  for i:=1 to length(s)-1 do 
    if (s[i]='R')and(s[i+1]='.')then begin
      writeln(i,' ',i+1);
      exit;
    end;
end.