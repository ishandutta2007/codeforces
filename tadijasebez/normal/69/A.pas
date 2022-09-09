program Main;
type
    niz=array[1..100] of int64;
var 
    n:int64;
    i:int64;
    sum_x:int64=0;
    sum_y:int64=0;
    sum_z:int64=0;
    zero:int64=0;
    x:niz;
    y:niz;
    z:niz;
begin
    readln(n);
    for i:=1 to n do
    begin
        readln(x[i],y[i],z[i]);
        sum_x+=x[i];
        sum_y+=y[i];
        sum_z+=z[i];
    end;
    if (sum_x=zero) and (sum_y=zero) and (sum_z=zero) then
        writeln('YES')
    else
        writeln('NO');
end.