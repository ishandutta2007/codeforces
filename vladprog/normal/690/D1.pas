var
  r,c,i,k:longint;
  s:string;

begin
  readln(r,c);
  for i:=1 to r do
    readln(s);
  if s[1]='B'
    then k:=1
    else k:=0;
  for i:=2 to c do
    if (s[i]='B')and(s[i-1]='.')
      then inc(k);
  writeln(k)
end.