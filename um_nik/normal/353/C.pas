var n,i,j,m,t:integer;
a,b:array [0..100100] of integer;
s:string;

begin
readln(n);
for i:=1 to n-1 do read(a[i]);
readln(a[n]);
b[0]:=0;
for i:=1 to n do b[i]:=a[i]+b[i-1];
readln(s);
t:=0;
for i:=1 to n do
  if s[i]='1' then t+=a[i];
m:=t;
i:=n;
while (i>0) do
  begin
  if s[i]='0' then i-=1 else break;
  end;
if i=0 then
  begin
  writeln(0);
  halt;
  end;
t:=0;
while i>0 do
  begin
  if s[i]='1' then
    begin
    if t+b[i-1]>m then m:=t+b[i-1];
    t+=a[i];
    end;
  i-=1;
  end;
writeln(m);
end.