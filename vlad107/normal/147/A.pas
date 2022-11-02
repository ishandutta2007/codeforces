var
  s,p:ansistring;
  i:longint;

begin
  readln(s);
  p:='';
  for i:=1 to length(s)do begin
    if (s[i]=' ')and(s[i+1]=' ')then continue;
    p:=p+s[i];
  end;
  s:=p;
  for i:=1 to length(s)do 
    if (s[i]in['.',',','!','?'])and(s[i+1]<>' ')then write(s[i],' ')else
    if (s[i]=' ')and(s[i+1]in['.',',','!','?'])then continue else
    write(s[i]);
  writeln;    
end.