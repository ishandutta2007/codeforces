var n,m,i,j,ans,s:integer;
a,b:array [1..200000] of integer;
c:array [1..600,1..600] of integer;
begin
for i:=2 to 200000 do a[i]:=1;
a[1]:=0;
for i:=2 to 100000 do
    begin
    j:=2;
    while i*j<=200000 do
        begin
        a[i*j]:=0;
        j+=1;
        end;
    end;
j:=2;
for i:=1 to 100000 do
    begin
    if i>j then
        begin
        j+=1;
        while a[j]=0 do j+=1;
        end;
    b[i]:=j-i;
    end;
readln(n,m);
for i:=1 to n do
    begin
    for j:=1 to m do read(c[i,j]);
    end;
ans:=1000000000;
for i:=1 to n do
    begin
    s:=0;
    for j:=1 to m do s+=b[c[i,j]];
    if s<ans then ans:=s;
    end;
for i:=1 to m do
    begin
    s:=0;
    for j:=1 to n do s+=b[c[j,i]];
    if s<ans then ans:=s;
    end;
writeln(ans);
end.