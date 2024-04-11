var n:integer;
s:string;
begin
readln(s);
if s[1]<>'-' then writeln(s) else
  begin
  n:=length(s);
  if ord(s[n])<ord(s[n-1]) then s[n-1]:=s[n];
  s:=copy(s,1,n-1);
  n-=1;
  if (n=2) and (s[2]='0') then writeln(0) else writeln(s);
  end;
end.