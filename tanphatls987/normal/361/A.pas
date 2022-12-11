var n,i,j,k:integer;
    a:array[1..100,1..100]of integer;
    c,d:array[1..100]of integer;
procedure printfile;
        begin
        for i:=1 to n do
                begin
                for j:=1 to n do
                write(a[i,j],' ');
                writeln('');
                end;
        halt;
        end;
procedure solve(x,y:integer);
        begin
        if y>n then solve(x+1,1)
        else
        if x<n then
                begin
                if y=n then a[x,y]:=k-d[x] else
                if c[y]>d[x] then a[x,y]:=random(k-c[y]) else a[x,y]:=random(k-d[x]);
                c[y]:=c[y]+a[x,y];
                d[x]:=d[x]+a[x,y];
                solve(x,y+1);
                end
        else
        if x=n then
                begin
                a[x,y]:=k-c[y];
                c[y]:=k;
                d[x]:=d[x]+a[x,y];
                if y=n then
                        begin
                        for i:=1 to n do
                        if (c[y]<>k) or (d[x]<>k) then exit;
                        printfile;
                        end;
                solve(x,y+1);
                end;
        end;
begin
readln(n,k);
fillchar(a,sizeof(a),0);
fillchar(d,sizeof(d),0);
fillchar(c,sizeof(c),0);
solve(1,1);
end.