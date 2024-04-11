var 
  i, n, a, b, res : longint;
  
begin
    read(n);
    for i := 1 to n do begin
        read(a, b);
        if (a + 2 <= b) then begin
            inc(res);
        end;
    end;
    writeln(res);
end.