var n,i,x:integer;
s:string;
begin
x:=0;
readln(n);
for i:=1 to n do
  begin
  readln(s);
  if (s='++X') or (s='X++') then x+=1 else
    begin
    if (s='--X') or (s='X--') then x-=1;
    end;
  end;
writeln(x);
end.