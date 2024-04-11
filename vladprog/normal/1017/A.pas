begin
    var n,a,b,c,d:integer;
    read(n,a,b,c,d);
    var s:=a+b+c+d;
    var ans:=1;
    for var i:=2 to n do
        begin
            read(a,b,c,d);
            if a+b+c+d>s then ans+=1;
        end;
    write(ans);
end.