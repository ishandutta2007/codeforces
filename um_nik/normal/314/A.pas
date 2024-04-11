var j:integer;
p,n,k,t,i,ans:int64;
a,d:array [1..300000] of int64;


begin
readln(n,k);
for j:=1 to n do read(a[j]);
d[1]:=0;
ans:=0;
p:=0;
t:=1;
for j:=2 to n do
  begin
  i:=j;
  d[i]:=p+((n-t+1)*(i-ans-2))*a[t]-(n-i)*(i-ans-1)*a[i];
  if d[i]<k then
    begin
    writeln(i);
    ans+=1;
    end else
    begin
    p:=d[i];
    t:=i;
    end;
  end;
//for i:=1 to n do write(d[i],' ');
end.