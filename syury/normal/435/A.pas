var c,n,i,j,ans,m:longint;
    a:array[1..100]of longint;

begin
readln(n,m);
for i:=1 to n do
   read(a[i]);
i:=1;ans:=0;
while i<=n do
begin
   c:=m;
   inc(ans);
   dec(c,a[i]);inc(i);
   while (i<=n)and(c>=a[i]) do begin dec(c,a[i]);inc(i);end;
end;
write(ans);
end.