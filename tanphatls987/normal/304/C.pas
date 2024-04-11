var i,n:integer;
begin
readln(n);
if (n mod 2=0) then write(-1) else if n>1 then
        begin
        for i:=0 to n-1 do write(i,' ');
        writeln;
        for i:=1 to n do write(i mod n,' ');
        writeln;
        for i:=0 to n-1 do write((2*i+1) mod n,' ');
        end
        else begin writeln(0);writeln(0);writeln(0);end;
end.