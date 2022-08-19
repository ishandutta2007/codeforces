var i,n,x,y,a,b:integer;
s:string;
begin
readln(n);
setlength(s,n);
x:=0;
y:=0;
for i:=1 to n do
  begin
  readln(a,b);
  if abs(x+a-y)<=500 then
    begin
    x+=a;
    s[i]:='A';
    end else
    begin
    y+=b;
    s[i]:='G';
    end;
  end;
writeln(s);
end.