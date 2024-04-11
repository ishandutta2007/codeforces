var n,k,i:integer;
begin
readln(n,k);
if n<3*k then writeln(-1) else
    begin
    for i:=1 to k do write(i,' ',i,' ');
    for i:=1 to k do write(i,' ');
    for i:=3*k+1 to n do write('1 ');
    end;
end.