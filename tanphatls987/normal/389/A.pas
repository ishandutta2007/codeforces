var i,n,cur,last:integer;
        a:array[1..100]of integer;
begin
readln(n);
for i:=1 to n do read(a[i]);
cur:=101;
repeat
        last:=cur;
        for i:=1 to n do if cur>a[i] then cur:=a[i];
        for i:=1 to n do
                begin
                a[i]:=a[i] mod cur;
                if a[i]=0 then a[i]:=cur;
                end;
until last=cur;
write(cur*n);
end.