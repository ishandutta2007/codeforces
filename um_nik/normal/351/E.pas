var n,i,j,k,p,s:integer;
a:array [1..2100] of integer;

begin
readln(n);
for i:=1 to n do read(a[i]);
for s:=1 to 30 do
  begin
  for i:=1 to n do
    begin
    k:=0;
    for j:=1 to n do
      if (j-i)*(a[j]-a[i])<0 then k+=1;
    a[i]*=-1;
    p:=0;
    for j:=1 to n do
      if (j-i)*(a[j]-a[i])<0 then p+=1;
    if p>k then a[i]*=-1;
    end;
  end;
k:=0;
for i:=1 to n-1 do
  begin
  for j:=i+1 to n do
    if a[j]<a[i] then k+=1;
  end;
writeln(k);
end.