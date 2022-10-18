var c1, c2, c3, c4, c5: longint;
    sum: longint;
begin
 readln(c1, c2, c3, c4, c5);
 sum:=c1+c2+c3+c4+c5;
 if (sum mod 5 = 0) and (sum > 0) then writeln(sum div 5)
 else writeln(-1);
end.