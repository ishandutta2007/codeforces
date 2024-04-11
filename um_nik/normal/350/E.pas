var n,m,i,k,j,p:integer;
a:array [1..300,1..300] of integer;
b,c:array [1..300] of integer;
d,e:array [1..50000] of integer;


begin
readln(n,m,k);
if k=n then
  begin
  writeln(-1);
  halt;
  end;
for i:=1 to n do c[i]:=0;
for i:=1 to k do
  begin
  read(b[i]);
  c[b[i]]:=1;
  end;
p:=k;
for i:=1 to n do
  begin
  if c[i]=0 then
    begin
    p+=1;
    b[p]:=i;
    end;
  end;

for i:=1 to n do
  for j:=1 to n do a[i,j]:=0;
a[1,n]:=1;
a[2,n]:=1;
for i:=2 to n-2 do a[i,i+1]:=1;
p:=n-1;
if p<m then
  begin
  for i:=1 to n-1 do
    begin
    for j:=i+1 to n do
      begin
      if ((i>1) or (j>k)) and (a[i,j]=0) then
        begin
        p+=1;
        a[i,j]:=1;
        end;
      if p=m then break;
      end;
    if p=m then break;
    end;
  end;
if p<m then
  begin
  writeln(-1);
  halt;
  end;
for i:=1 to n do
  for j:=i+1 to n do
    begin
    if a[i,j]=1 then
      begin
      writeln(b[i],' ',b[j]);
      end;
    end;
end.