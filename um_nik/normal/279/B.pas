var m,p,n,t,s,i,j:integer;
a:array [1..200000] of integer;
begin
readln(n,t);
for i:=1 to n do read(a[i]);
a[n+1]:=t+1;
s:=0;
m:=0;
p:=0;
j:=0;
for i:=1 to n do
  begin
  while s<=t do
    begin
    j+=1;
    s+=a[j];
    end;
  p:=j-i;
  if m<p then m:=p;
  s-=a[i];
  end;
writeln(m);
end.