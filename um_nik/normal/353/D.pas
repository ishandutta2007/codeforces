var n,i,m,k,p:integer;
s:string;
begin
readln(s);
n:=length(s);
i:=1;
while i<=n do
  begin
  if s[i]='F' then i+=1 else break;
  end;
if i=n+1 then
  begin
  writeln(0);
  halt;
  end;
s:=copy(s,i,n-i+1);
n:=length(s);
i:=n;
while i>0 do
  begin
  if s[i]='M' then i-=1 else break;
  end;
if i=0 then
  begin
  writeln(0);
  halt;
  end;
s:=copy(s,1,i);
n:=length(s);
k:=0;
for i:=1 to n do
  begin
  if s[i]='F' then k+=1;
  end;
m:=0;
for i:=1 to n do
  begin
  if s[i]='F' then
    begin
    k-=1;
    if k+p>m then m:=k+p;
    end else p+=1;
  end;
writeln(m);
end.