var i,n,m,k,j:integer;
a,b,s,c:array [1..100100] of integer;

procedure qsort(x,y:integer);
var i,j,m,z:integer;
begin
if x>=y then exit;
i:=x;
j:=x+random(y-x+1);
m:=s[j];
j:=y;
while i<=j do
    begin
    while s[i]<m do i+=1;
    while s[j]>m do j-=1;
    if i<=j then
        begin
        z:=s[i];
        s[i]:=s[j];
        s[j]:=z;
        z:=c[i];
        c[i]:=c[j];
        c[j]:=z;
        i+=1;
        j-=1;
        end;
    end;
qsort(x,j);
qsort(i,y);
end;

procedure sort(x,y:integer);
var i,j,m,z:integer;
begin
if x>=y then exit;
i:=x;
j:=x+random(y-x+1);
m:=c[j];
j:=y;
while i<=j do
    begin
    while c[i]<m do i+=1;
    while c[j]>m do j-=1;
    if i<=j then
        begin
        z:=c[i];
        c[i]:=c[j];
        c[j]:=z;
        z:=a[i];
        a[i]:=a[j];
        a[j]:=z;
        z:=b[i];
        b[i]:=b[j];
        b[j]:=z;
        i+=1;
        j-=1;
        end;
    end;
sort(x,j);
sort(i,y);
end;

begin
readln(n);
for i:=1 to n do read(s[i]);
for i:=1 to n do c[i]:=i;
qsort(1,n);
writeln('YES');
m:=n-((n+2) div 3);
k:=n-m+1;
if k>n then k:=n;
for i:=1 to n do a[i]:=-1;
for i:=1 to k do a[i]:=0;
for i:=1 to m-k do a[n+1-i]:=i;
j:=m-k+1;
if j<1 then j:=1;
for i:=k+1 to n-m+k do
    begin
    a[i]:=j;
    j+=1;
    end;
for i:=1 to n do b[i]:=s[i]-a[i];
sort(1,n);
for i:=1 to n do write(a[i],' ');
writeln();
for i:=1 to n do write(b[i],' ');
writeln();
end.