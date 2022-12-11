var i,n,k:integer;
    a:array[1..100000]of integer;   
begin
readln(n,k);
if k=n then begin write(-1);halt; end;
a[1]:=(k+2) mod n;
a[n]:=1;
if a[1]=0 then a[1]:=n;
for i:=2 to k+1 do a[i]:=i;
for i:=k+2 to n-1 do a[i]:=i+1;
for i:=1 to n do write(a[i],' ');
end.