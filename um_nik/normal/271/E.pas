var n,i,j,k:integer;
m,ans,s,p:int64;
a:array [1..100000] of int64;
b:array [1..10000] of int64;

function gcd(x,y:int64):int64;
begin
if y=0 then gcd:=x else gcd:=gcd(y,x mod y);
end;

begin
readln(n,m);
for i:=1 to n do
    begin
    read(a[i]);
    a[i]-=1;
    end;
p:=a[1];
for i:=2 to n do
    begin
    if p>a[i] then p:=gcd(p,a[i]) else p:=gcd(a[i],p);
    end;
k:=0;
while p mod 2=0 do p:=p div 2;
for i:=1 to trunc(sqrt(p)) do
    begin
    if p mod i=0 then
        begin
        k+=2;
        b[k-1]:=i;
        b[k]:=p div i;
        end;
    end;
if trunc(sqrt(p))=sqrt(p) then k-=1;
n:=k;
for i:=1 to n do
    begin
    p:=b[i];
    while 2*p<=m do
        begin
        k+=1;
        p*=2;
        b[k]:=p;
        end;
    end;
ans:=0;
for i:=1 to k do
    begin
    ans+=m-b[i];
    end;
writeln(ans);
end.