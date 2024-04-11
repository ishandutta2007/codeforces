var t,k,n,i,x,m,ans:integer;
begin
readln(n);
ans:=0;
m:=100000;
k:=0;
t:=0;
for i:=1 to 2*n-1 do
  begin
  read(x);
  if x<0 then k+=1;
  if x=0 then t:=1;
  ans+=abs(x);
  if abs(x)<m then m:=abs(x);
  end;
if (n mod 2=0) and (t=0) and (k mod 2=1) then ans-=2*m;
writeln(ans);
end.