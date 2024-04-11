{$r-,q-,s-,i-,o+}
var
  d,max,t:int64;
  n,x,y,z:longint;
  
  function gcd(x,y:int64):int64;
    begin
      while (x<>0)and(y<>0)do
        if (x>y)then x:=x mod y else y:=y mod x;
      gcd:=x+y;
    end;

begin
  read(n);
  max:=0;
  for x:=n-100 to n do if (x>=1)then 
    for y:=n-100 to n do if (y>=1)then 
      for z:=n-100 to n do if (z>=1)then begin
        d:=gcd(x,y);
        t:=int64(x)*y div d;
        d:=gcd(t,z);
        t:=t*z div d;
        if (t>max)then begin
          max:=t;
        end;
      end;
  writeln(max);
end.