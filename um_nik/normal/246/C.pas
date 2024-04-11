var n,k,p,s,i,j:integer;
a:array [1..50] of integer;
begin
readln(n,k);
for i:=1 to n do read(a[i]);
for i:=1 to n-1 do
  begin
  for j:=1 to n-i do
    begin
    if a[j]<a[j+1] then
      begin
      p:=a[j];
      a[j]:=a[j+1];
      a[j+1]:=p;
      end;
    end;
  end;
p:=1;
s:=0;
i:=1;
while i<=k do
  begin
  s:=s+1;
  if s>n then
    begin
    p:=p+1;
    s:=p;
    end;
  write(p,' ');
  for j:=1 to p-1 do write(a[j],' ');
  writeln(a[s]);
  i:=i+1;
  end;
end.