var i,n:integer;
a,b:int64;
s:string;
begin
readln(a,s);
n:=length(s)-1;
s:=copy(s,2,n);
b:=0;
for i:=n downto 1 do
  begin
  b:=b*10+ord(s[i])-48;
  end;
writeln(a+b);
end.