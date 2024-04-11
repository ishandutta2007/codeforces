var s:string;
i,n,k:integer;
a:array [1..100] of integer;
begin
readln(s);
for i:=1 to 26 do a[i]:=0;
n:=length(s);
for i:=1 to n do a[ord(s[i])-96]+=1;
k:=0;
for i:=1 to 26 do
  begin
  if a[i] mod 2=1 then k+=1;
  end;
if (k=0) or (k mod 2=1) then writeln('First') else writeln('Second');
end.