var t,x,y,n,i,k,m:integer;
ans:real;
a:array [1..300000] of integer;
b:array [1..300000] of integer;
begin
n:=1;
a[1]:=0;
readln(m);
for i:=1 to m+10 do b[i]:=0;
ans:=0;
for i:=1 to m do
  begin
  read(t);
  if t=1 then
    begin
    read(x,y);
    b[x]+=y;
    ans+=x*y/n;
    end;
  if t=2 then
    begin
    read(x);
    n+=1;
    a[n]:=x;
    ans:=ans*((n-1)/n)+x/n;
    end;
  if t=3 then
    begin
    b[n-1]+=b[n];
    ans:=ans*(n/(n-1))-(a[n]+b[n])/(n-1);
    b[n]:=0;
    n-=1;
    end;
  writeln(ans:20:8);
  end;
end.