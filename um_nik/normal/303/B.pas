var n,m,x0,y0,x1,x2,y1,y2,a,b,g:int64;

function gcd(x,y:int64):int64;
var x4,y4:int64;
begin
x4:=x;
y4:=y;
if x<y then
  begin
  x4:=y;
  y4:=x;
  end;
if y4=0 then gcd:=x4 else gcd:=gcd(y4,x4 mod y4);
end;

begin
read(n,m,x0,y0,a,b);
g:=gcd(a,b);
a:=a div g;
b:=b div g;
x2:=n div a;
y2:=m div b;
//writeln(g,' ',x2,' ',y2);
if y2<x2 then x2:=y2;
y2:=x2*b;
x2*=a;
//writeln(x2,' ',y2);
x1:=x0-((x2+1) div 2);
y1:=y0-((y2+1) div 2);
x2+=x1;
y2+=y1;
//writeln(x1,' ',y1,' ',x2,' ',y2);
if x1<0 then
  begin
  x2-=x1;
  x1:=0;
  end;
//writeln(x1,' ',y1,' ',x2,' ',y2);
if y1<0 then
  begin
  y2-=y1;
  y1:=0;
  end;
//writeln(x1,' ',y1,' ',x2,' ',y2);
if x2>n then
  begin
  x1:=x1-x2+n;
  x2:=n;
  end;
//writeln(x1,' ',y1,' ',x2,' ',y2);
if y2>m then
  begin
  y1:=y1-y2+m;
  y2:=m;
  end;
writeln(x1,' ',y1,' ',x2,' ',y2);
end.