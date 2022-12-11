var n,i,ans,last:integer;
        s:ansistring;
begin
readln(n);
readln(s);
s:='L'+s;
s:=s+'R';
ans:=0;last:=1;
for i:=2 to n+2 do if (s[i]<>'.') then
        begin
        if ((s[last]='L')and(s[i]='R')) then ans:=ans+i-last-1;
        if ((s[last]='R')and(s[i]='L')) then ans:=ans+((i-last-1)mod 2);
        last:=i;
        end;
writeln(ans);
end.