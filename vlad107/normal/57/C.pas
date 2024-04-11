{$r-,q-,s-,i-,o+}
const
  base:int64=1000000007;
var
  x,y:int64;
  n:longint;
  function fact(n:longint):int64;
    var
      i:longint;
      x:int64;
    begin
      x:=1;
      for i:=1 to n do
        x:=int64(x)*i mod int64(base);
      fact:=x;
    end;
  function pow(x,y:longint):int64;
    var
      t:int64;
    begin
      if (y=0)then begin
        pow:=1;
        exit;
      end;
      if (y mod 2=1)
        then pow:=pow(x,y-1)*x mod base
        else begin
          t:=pow(x,y div 2);
          pow:=t*t mod base;
        end;
    end;
begin
  read(n);
  x:=fact(2*n);
  y:=fact(n);
  y:=y*y mod base;
  x:=x*pow(y,base-2);
  x:=x mod base;
  dec(x,n);
  while (x<0)do inc(x,base);
  writeln(x);
end.