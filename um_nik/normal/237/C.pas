var m,a,b,k,i,n,p,f,j,q:integer;
prime:array [1..1001000] of integer;
c:array [1..1000000] of integer;
begin
readln(a,b,k);
prime[1]:=0;
for i:=2 to 1001000 do prime[i]:=1;
for j:=2 to 500500 do
begin
i:=2;
while i*j<=1001000 do
begin
prime[i*j]:=0;
i:=i+1;
end;
end;
p:=0;
i:=a;
f:=0;
q:=0;
while p<k do
begin
if prime[i]=1 then p:=p+1;
if p=k then
begin
f:=i;
break;
end;
if i=b then
begin
f:=-1;
break;
end;
i:=i+1;
end;
if f=-1 then writeln(-1) else
begin
c[a]:=f-a+1;
m:=f-a+1;
i:=a+1;
while f<=b do
begin
n:=m;
if prime[i-1]=0 then c[i]:=c[i-1]-1 else
begin
j:=f+1;
while prime[j]=0 do j:=j+1;
c[i]:=c[i-1]-1+j-f;
if c[i]>m then n:=c[i] else n:=m;
f:=j;
end;
if f<=b then m:=n else
begin
if i+m-1<=b then m:=b+2-i;
end;
i:=i+1;
end;
writeln(m);
end;
end.