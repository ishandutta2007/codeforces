var n,i,x,y,t,s1,s2:integer;
begin
t:=0;
readln(n);
s1:=0;
s2:=0;
for i:=1 to n do
  begin
  readln(x,y);
  s1+=x;
  s2+=y;
  if (x+y) mod 2=1 then t:=1;
  end;
if (s1+s2) mod 2=1 then writeln(-1) else
  begin
  if (s1 mod 2=0) then writeln(0) else
    begin
    if t=1 then writeln(1) else writeln(-1);
    end;
  end;
end.