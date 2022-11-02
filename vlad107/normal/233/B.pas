const
  inf:int64=1000000000000000000;

var
  x,n,ans,d,q:int64;
  s:longint;
  
  function sum(x:int64):longint;
    var
      res:longint;
    begin
      res:=0;
      while (x>0)do begin
        res:=res+x mod 10;
        x:=x div 10;
      end;
      sum:=res;
    end;

begin
  read(n);
  ans:=inf;
  for s:=1 to 9*18 do begin
    //x^2+s*x-n=0
    d:=s*s+4*n;
    q:=trunc(sqrt(d));
    if (q*q=d)then begin
      if (-s+q>0)and((-s+q)mod 2=0)then begin
        x:=(-s+q)div 2;
        if (sum(x)=s)and(x<ans)then ans:=x;
      end;
    end;
  end;
  if (ans=inf)then ans:=-1;
  writeln(ans);
end.