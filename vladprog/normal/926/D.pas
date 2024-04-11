var
    s:array[1..6] of string;
    ans,i:integer;

procedure f(i,a,b:integer);
begin
    if (s[i][1]='.') and (ans<a) then ans:=a;
    if (s[i][2]='.') and (ans<a) then ans:=a;
    if (s[i][4]='.') and (ans<b) then ans:=b;
    if (s[i][5]='.') and (ans<b) then ans:=b;
    if (s[i][7]='.') and (ans<a) then ans:=a;
    if (s[i][8]='.') and (ans<a) then ans:=a;
end;

procedure print;
begin
    for i:=1 to 6 do
        writeln(s[i]);
    halt;
end;

procedure g(i,a,b:integer);
begin
    if (s[i][1]='.') and (ans=a) then begin s[i][1]:='P'; print end;
    if (s[i][2]='.') and (ans=a) then begin s[i][2]:='P'; print end;
    if (s[i][4]='.') and (ans=b) then begin s[i][4]:='P'; print end;
    if (s[i][5]='.') and (ans=b) then begin s[i][5]:='P'; print end;
    if (s[i][7]='.') and (ans=a) then begin s[i][7]:='P'; print end;
    if (s[i][8]='.') and (ans=a) then begin s[i][8]:='P'; print end;
end;

begin
    for i:=1 to 6 do
        readln(s[i]);
    f(1,3,4);
    f(2,3,4);
    f(3,2,3);
    f(4,2,3);
    f(5,1,2);
    f(6,1,2);
    
    g(1,3,4);
    g(2,3,4);
    g(3,2,3);
    g(4,2,3);
    g(5,1,2);
    g(6,1,2);
end.