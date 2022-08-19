var n,i,x:integer;
s:string;
begin
readln(s);
readln(x);
n:=length(s);
for i:=1 to n do
  begin
  if ord(s[i])<93 then s[i]:=chr(ord(s[i])+32);
  if (ord(s[i])<97+x) then s[i]:=chr(ord(s[i])-32);
  end;
writeln(s);
end.