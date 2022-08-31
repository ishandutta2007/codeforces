var i,n,k:integer;
s:string;
a:array [1..26] of integer;
begin
readln(s);
n:=length(s);
for i:=1 to 26 do a[i]:=0;
for i:=1 to n do
begin
if a[ord(s[i])-96]=0 then a[ord(s[i])-96]:=1;
end;
k:=0;
for i:=1 to 26 do k:=k+a[i];
if k mod 2=0 then writeln('CHAT WITH HER!') else writeln('IGNORE HIM!');
end.