var n,i,j,k,m:integer;
a:array [1..8] of int64;
b:array [1..8] of integer;
z,x:int64;
c:array [1..8,0..50] of integer;
d:array [1..8] of int64;

function res():integer;
var i,j,p:integer;
begin

for i:=1 to n do d[i]:=a[i];
for i:=2 to n do
  begin
  if b[i]>0 then
    begin
    if d[b[i]] mod a[i]=0 then d[b[i]]:=d[b[i]] div a[i] else
      begin
      res:=1000000001;
      exit;
      end;
    end;
  end;
p:=0;
for i:=2 to n do
  if b[i]=0 then p:=1;
p+=c[1,0]+1;
for i:=2 to n do
  if b[i]=0 then p+=c[i,0]+1 else
    begin
    if c[i,0]>0 then p+=1;
    end;
res:=p;

end;


begin
readln(n);
for i:=1 to n do read(a[i]);
for i:=1 to n-1 do
  for j:=1 to n-i do
    begin
    if a[j]<a[j+1] then
      begin
      z:=a[j];
      a[j]:=a[j+1];
      a[j+1]:=z;
      end;
    end;
//for i:=1 to n do write(a[i],' ');
//writeln();
for i:=1 to n do
  begin
  c[i,0]:=0;
  x:=a[i];
  k:=2;
  while k<=trunc(sqrt(x)) do
    begin
    while x mod k=0 do
      begin
      c[i,0]+=1;
      c[i,c[i,0]]:=k;
      x:=x div k;
      end;
    k+=1;
    end;
  if x>1 then
    begin
    c[i,0]+=1;
    c[i,c[i,0]]:=x;
    end;
  end;
for i:=1 to n do
  if c[i,0]=1 then c[i,0]:=0;
if n=1 then
  begin
  writeln(1+c[1,0]);
  halt;
  end;
m:=1000000000;
for i:=2 to n do
  begin
  b[i]:=0;
  end;
b[n]:=-1;
while true do
  begin
  k:=n;
  while (b[k]=k-1) and (k>1) do k-=1;
  if k=1 then break;
  b[k]+=1;
  for i:=k+1 to n do b[i]:=0;
  k:=res();
{  if k<100000 then
    begin
    for i:=2 to n do write(b[i],' ');
    writeln(k);
    end;
}  if k<m then m:=k;
  end;
writeln(m);
end.