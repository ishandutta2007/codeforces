const
  INF=10000010;
var
  q:array[-INF..INF]of int64;
  c,o,x,y:int64;
  l,r:extended;
  i,n,m,b:longint;
begin
  read(n,m);
  for b:=1 to n do begin
    c:=int64(b)*b;
    l:=c;
    if (l>m)then l:=m;
    l:=c-l;
    r:=c-1;
    o:=o+2*trunc(r-l+1);
    x:=trunc(sqrt(l)+1-1e-8);
    y:=trunc(sqrt(r));
    if (y<x)then continue;
    dec(o,2*(y-x+1));
    inc(q[-b-y-1]);dec(q[-b-x]);
    inc(q[-b+x-1]);dec(q[-b+y]);
  end;
  c:=0;
  for i:=-INF to INF do begin
    inc(c,q[i]);
    inc(o,ord(c>0));
  end;
  writeln(o);
end.