{$r-,q-,s-,i-,o+}
var
  mid,n,x,y,ll,rr:longint;
  c:int64;
  
  function f(t:longint):int64;
    begin
      f:=int64(t)*(t+1)div 2;
    end;
    
  function g(x:longint):int64;
    begin
      g:=x+2*f(x-1);
    end;
    
  function dist(x1,y1,x2,y2:longint):longint;
    begin
      dist:=abs(x1-x2)+abs(y1-y2);
    end;
  
  function kol(t:longint):int64;
    var
      ct:int64;
      
    begin
      inc(t);
      ct:=2*g(t-1)+2*t-1;
      if (x+t-1>n)then ct:=ct-g(x+t-1-n);
      if (y+t-1>n)then ct:=ct-g(y+t-1-n);
      if (x<t)then ct:=ct-g(t-x);
      if (y<t)then ct:=ct-g(t-y);
      if (dist(x,y,0,0)<t)then ct:=ct+f(t-dist(x,y,0,0));
      if (dist(x,y,0,n+1)<t)then ct:=ct+f(t-dist(x,y,0,n+1));
      if (dist(x,y,n+1,0)<t)then ct:=ct+f(t-dist(x,y,n+1,0));
      if (dist(x,y,n+1,n+1)<t)then ct:=ct+f(t-dist(x,y,n+1,n+1));
      kol:=ct;
    end;

begin
  read(n,x,y,c);
  ll:=0;rr:=c;
  while (ll<rr-1)do begin
    mid:=(ll+rr)shr 1;
    if (kol(mid)>=c)
      then rr:=mid
      else ll:=mid;
  end;
  if (kol(ll)>=c)
    then writeln(ll)
    else writeln(rr);
end.