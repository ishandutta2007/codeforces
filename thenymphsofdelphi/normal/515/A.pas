var
    a, b, n, sum: longint;

begin
    read(a, b, n);
    sum := abs(a) + abs(b);
    if sum > n then
    begin
        write('No');
        halt(0);
    end;
    if (n - sum) mod 2 = 0 then
        write('Yes')
    else
        write('No');
end.