var n,l,d,i,t,k,min,max,s:integer;
a:array [1..100] of integer;
begin
readln(n,d,l);
k:=d;
min:=(1-l)*(n div 2)+(n mod 2);
max:=(l-1)*(n div 2)+l*(n mod 2);
if (d>=min) and (d<=max) then
begin
for i:=1 to n do
begin
t:=d;
if i mod 2=1 then
begin
if t>l then
begin
d:=d-l;
a[i]:=l;
end;
if (t>0) and (t<=l) then
begin
d:=0;
a[i]:=t;
end;
if (t<=0) then
begin
d:=d-1;
a[i]:=1;
end;
end else
begin
if (t<0-l) then
begin
d:=d+l;
a[i]:=l;
end;
if (t<0) and (t>=0-l) then
begin
d:=0;
a[i]:=0-t;
end;
if (t>=0) then
begin
d:=d+1;
a[i]:=1;
end;
end;
end;
s:=0;
for i:=1 to n do
begin
if i mod 2=1 then s:=s+a[i] else s:=s-a[i];
end;
if s<>k then a[n-1]:=a[n-1]+1;
for i:=1 to n do
write(a[i],' ');
end else writeln(-1);
end.