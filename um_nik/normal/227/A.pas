var x,y:array [1..3] of int64;
i:integer;
begin
for i:=1 to 3 do
readln(x[i],y[i]);
if (x[2]-x[1])*(y[3]-y[2])=(x[3]-x[2])*(y[2]-y[1]) then writeln('TOWARDS') else
begin
if ((x[2]>x[1]) and (y[3]<y[2])) or ((x[2]=x[1]) and ((y[1]-y[2])*(x[2]-x[3])>0)) or ((x[2]<x[1]) and (y[3]>y[2])) then writeln('RIGHT') else writeln('LEFT');
end;
end.