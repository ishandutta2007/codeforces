const mmod=1000000009;
var n,m,k,p,ans:int64;

function bp(x,y:int64):int64;
begin
if y<3 then
  begin
  if y=1 then bp:=x else bp:=(x*x) mod mmod;
  end else
  begin
  if y mod 2=0 then bp:=bp(bp(x,y div 2),2) else bp:=(bp(bp(x,y div 2),2)*x) mod mmod;
  end;
end;


begin
readln(n,m,k);
p:=n div k;
if m+p<=n then writeln(m) else
  begin
  p:=m+p-n;
  m-=k*p;
  ans:=((bp(2,p)-1)*2*k) mod mmod;
  ans+=m;
  ans:=ans mod mmod;
  writeln(ans);
  end;
end.