var s1,s2:string;
i,m,n,a,b:integer;
begin
readln(s1);
readln(s2);
m:=length(s1);
n:=length(s2);
a:=0;
b:=0;
for i:=1 to m do
    if s1[i]='1' then a+=1;
for i:=1 to n do
    if s2[i]='1' then b+=1;
a+=a mod 2;
if a>=b then writeln('YES') else writeln('NO');
end.