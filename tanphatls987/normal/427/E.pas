var a:array[1..1000000]of longint;
    ans,tmp:int64;
    i,j,b,n,m:longint;
begin
readln(n,m);
for i:=1 to n do read(a[i]);
b:=(((n+m-2)div m)div 2)*m+1;
i:=1;j:=n;ans:=0;
while (i<b) do
    begin
         tmp:=a[b]-a[i];
         ans:=ans+2*tmp;
         i:=i+m;
    end;
    while (j>b) do
    begin
         tmp:=a[j]-a[b];
         ans:=ans+2*tmp;
         j:=j-m;
    end;
writeln(ans);
end.