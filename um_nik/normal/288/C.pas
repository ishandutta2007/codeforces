var n,i:integer;
ans,r:int64;
a:array [0..2000000] of int64;
b:array [0..25] of int64;

procedure p(x:integer);
var i,t,y:integer;
begin
if x=0 then
  begin
  a[0]:=0;
  exit;
  end;
if x=1 then
  begin
  a[0]:=1;
  a[1]:=0;
  exit;
  end;
if x<0 then exit;
t:=0;
while b[t+1]<=x do t+=1;
for i:=b[t] to x do
  begin
  a[i]:=b[t+1]-i-1;
  a[b[t+1]-i-1]:=i;
  end;
y:=b[t+1]-x-2;
p(y);
end;

begin
readln(n);
b[0]:=1;
for i:=1 to 25 do b[i]:=2*b[i-1];
p(n);
ans:=0;
for i:=0 to n do
  begin
  r:=i;
  ans+=r xor a[i];
  end;
writeln(ans);
for i:=0 to n do write(a[i],' ');
end.