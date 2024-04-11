var i, n, l, r: longint;
    a, b, cntA, cntB: array [1..100000] of longint;

function Solve(): boolean;
begin
    for i:=1 to l-1 do
        if a[i] <> b[i] then exit(false);
    for i:=r+1 to n do
        if a[i] <> b[i] then exit(false);
    for i:=l to r do 
        begin
            inc(cntA[a[i]]);
            inc(cntB[b[i]]);
        end;
    for i:=1 to 100000 do
        if (cntA[i] <> cntB[i]) then exit(false);
    exit(true);
end;

begin
    readln(n, l, r);
    for i:=1 to n do read(a[i]);
    for i:=1 to n do read(b[i]);
      
    if Solve() then writeln('TRUTH')
    else writeln('LIE');
  
end.