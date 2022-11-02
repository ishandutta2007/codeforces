{$r-,q-,s-,i-,o+}
var
  d,x1,y1,x2,y2,n,m,x,y,a,b,k:int64;
  
  function gcd(a,b:int64):Int64;
    begin
      while (a<>0)and(b<>0)do
        if (a>b)then a:=a mod b else b:=b mod a;
      gcd:=a+b;
    end;
  
begin
  read(n,m,x,y,a,b);
  d:=gcd(a,b);
  a:=a div d;
  b:=b div d;
  k:=n div a;
  if (m div b<k)then k:=m div b;
  a:=k*a;
  b:=k*b;
  x1:=x-((a+1) div 2);
  if (x1<0)then x1:=0;
  if (x1+a>n)then x1:=n-a;
  x2:=x1+a;
  y1:=y-((b+1)div 2);
  if (y1<0)then y1:=0;
  if (y1+b>m)then y1:=m-b;
  y2:=y1+b;
  writeln(x1,' ',y1,' ',x2,' ',y2);  
end.