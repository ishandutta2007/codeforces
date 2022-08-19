var ans,i,d,s,k,l,h:integer;
n:int64;
begin
readln(n);
ans:=-1;
k:=trunc(sqrt(n));
l:=trunc(sqrt(n+1640))-51;
if l<1 then l:=1;
for i:=l to k do
begin
if n mod i=0 then
begin
h:=(n div i)-i;
d:=i;
s:=0;
while d>0 do
begin
s:=s+d mod 10;
d:=d div 10;
end;
if h=s then
begin
ans:=i;
break;
end;
end;
end;
writeln(ans);
end.