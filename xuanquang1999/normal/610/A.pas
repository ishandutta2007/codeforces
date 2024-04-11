var n: longint;
begin
 readln(n);
 if (n mod 2 = 1) then writeln(0)
 else writeln(((n div 2) - 1) div 2);
end.