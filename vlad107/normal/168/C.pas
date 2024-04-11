const
  eps=1e-9;

var
  v,a,t0,tt,maxt,d,s,t:extended;
  i,n:longint;

begin
  read(n,a,d);
  maxt:=0;
  for i:=1 to n do begin
    read(t0,v);
    t:=v/a;
    s:=a*t*t/2;
    if (s+eps>d)
      then tt:=t0+sqrt(2*d/a)
      else tt:=t0+t+(d-s)/v;
    if (tt>maxt)then maxt:=tt;
    writeln(maxt:0:10);
  end;
end.