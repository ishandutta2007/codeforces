var n,k,i:integer;
    a:array[0..10000]of longint;
procedure solve;
var tmp:real;
        begin
        for k:=1 to n do
                begin
                a[k]:=a[k-1];
                for i:=1 to k-2 do
                        begin
                        tmp:=sqrt(k*k-i*i);
                        if ((tmp=trunc(tmp)) and (tmp>i)) then inc(a[k]);
                        end;
                end;
        write(a[n]);
        end;
begin
readln(n);
solve;
end.