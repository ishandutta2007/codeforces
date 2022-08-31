var j,m,n,k,i,t,p:integer;
a,b:array [1..100100] of integer;

procedure qsorta(x,y:integer);
var i,j,m,z:integer;
begin
if x>=y then exit;
i:=x;
j:=x+random(y-x+1);
m:=a[j];
j:=y;
while i<=j do
    begin
    while a[i]>m do i+=1;
    while a[j]<m do j-=1;
    if i<=j then    
        begin
        z:=a[i];
        a[i]:=a[j];
        a[j]:=z;
        i+=1;
        j-=1;
        end;
    end;
qsorta(x,j);
qsorta(i,y);
end;

procedure qsortb(x,y:integer);
var i,j,m,z:integer;
begin
if x>=y then exit;
i:=x;
j:=x+random(y-x+1);
m:=b[j];
j:=y;
while i<=j do
    begin
    while b[i]>m do i+=1;
    while b[j]<m do j-=1;
    if i<=j then    
        begin
        z:=b[i];
        b[i]:=b[j];
        b[j]:=z;
        i+=1;
        j-=1;
        end;
    end;
qsortb(x,j);
qsortb(i,y);
end;


begin
readln(m,n,k);
for i:=1 to m do read(a[i]);
for i:=1 to n do read(b[i]);
qsorta(1,m);
qsortb(1,n);
a[m+1]:=0;
b[n+1]:=0;
j:=1;
i:=1;
t:=0;
while i<=n do
    begin
    while b[i]=b[i+1] do i+=1;
    p:=b[i];
    
    while a[j]>p do j+=1;
    
    if j>i then
        begin
        t:=1;
        break;
        end;
        
    while a[j]=p do j+=1;
    
    if j>i+1 then
        begin
        t:=1;
        break;
        end;
    
    
    i+=1;
    end;
if (t=1) or (m>n) then writeln('YES') else writeln('NO');
end.