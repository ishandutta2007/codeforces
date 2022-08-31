var i,n:integer;
begin
readln(n);
i:=n;
while true do
    begin
    i+=1;
    if (i div 1000<>(i mod 1000) div 100) and (i div 1000<>(i mod 100) div 10) and (i div 1000<>(i mod 10) div 1) and ((i mod 1000) div 100<>(i mod 100) div 10) and ((i mod 1000) div 100<>(i mod 10) div 1) and ((i mod 100) div 10<>(i mod 10) div 1) then
        begin
        writeln(i);
        break;
        end;
    end;
end.