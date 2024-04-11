var n,m,i,k1,k2:integer;
s1,s2:string;
begin
readln(s1);
readln(s2);
n:=length(s1);
m:=length(s2);
if n<>m then writeln('NO') else
  begin
  k1:=0;
  k2:=0;
  for i:=1 to n do
    begin
    if s1[i]='1' then k1:=1;
    if s2[i]='1' then k2:=1;
    end;
  if (k1=k2) then writeln('YES') else writeln('NO');
  end;
end.