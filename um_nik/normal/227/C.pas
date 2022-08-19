var i,m,n:integer;
a:int64;
function p(b:int64;c:integer):int64;
begin
if c=1 then p:=b mod m else
begin
if c=2 then p:=(b*b) mod m else
begin
if c mod 2=0 then p:=(p(p(b,c div 2),2)) mod m else p:=(((p(p(b,c div 2),2)) mod m)*b) mod m;
end;
end;
end;
begin
readln(n,m);
a:=p(3,n);
a:=a-1;
if a<0 then a:=a+m;
writeln(a);
end.