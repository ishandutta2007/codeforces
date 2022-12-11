var a:array[1..2000] of longint;
    i,n,k,j,t:longint;
    ch:char;
    
begin
    ch := 'a';
    read(n);
    for i := 1 to n do read(a[i]);
    for i := 1 to n do begin
        k := n - i + 1;
        if a[k] = 0 then continue
        else begin
            for j := 1 to a[k] do begin
                for t := 1 to k do write(ch);
                if ch = 'z' then ch := 'a' else ch := chr(ord(ch) + 1);
            end;
            
            for j := 1 to k - 1 do a[j] := a[j] - (k - j + 1) * a[k];
        end;
    end;
end.