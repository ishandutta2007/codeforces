const
  base=1000000007;

var
  cr,ans,i,a,b,n:longint;
  fact,rev:array[0..1111111]of longint;
  
  function C(n,k:longint):longint;
    var
      res:longint;
    begin
      res:=int64(fact[n])*rev[k] mod base;
      res:=int64(res)*rev[n-k] mod base;
      C:=res;
    end;
  
  function check(x:longint):boolean;
    begin
      check:=false;
      while (x>0)do begin
        if (x mod 10<>a)and(x mod 10<>b)then exit;
        x:=x div 10;
      end;
      check:=true;
    end;
    
  function pow(x,y:longint):longint;
    var
      res:longint;
      
    begin
      res:=1;
      while (y>0)do begin
        if (y and 1=1)then res:=int64(res)*x mod base;
        x:=int64(x)*x mod base;
        y:=y shr 1;
      end;
      pow:=res;
    end;

begin
  read(a,b,n);
  fact[0]:=1;
  for i:=1 to n do fact[i]:=int64(fact[i-1])*i mod base;
  for i:=0 to n do rev[i]:=pow(fact[i],base-2);
  ans:=0;
  for i:=0 to n do
    if (check(i*a+(n-i)*b))then begin
      cr:=C(n,i);
      ans:=ans+cr;
      if (ans>=base)then dec(ans,base);
    end;
  writeln(ans);
end.