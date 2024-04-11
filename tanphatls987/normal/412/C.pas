var n,i,j,find:longint;
    a:array[1..100000]of string;
    last:string;
begin
readln(n);
for i:=1 to n do readln(a[i]);
for j:=1 to length(a[1]) do
        begin
        last:=a[1][j];
        for i:=1 to n do if (a[i][j]<>last) then
                begin
                if last='?' then last:=a[i][j] else
                        begin
                        if (a[i][j]<>'?') then begin write('?');last:='';break;end;
                        end;
                end;
        if last<>'' then begin if (last<>'?') then write(last) else write('a');end;
        end;
end.