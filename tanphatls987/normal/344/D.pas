var a:ansistring;
    b:array[0..100000]of char;
    i,j:longint;
begin
readln(a);
b[1]:=a[1];j:=1;
for i:=2 to length(a) do if (a[i]=b[j]) then dec(j) else begin inc(j);b[j]:=a[i];end;
if (j>0) then writeln('No') else writeln('Yes');
end.