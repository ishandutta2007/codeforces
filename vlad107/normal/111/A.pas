var
  t,i,n,y:longint;
  x:int64;

begin
  read(n,x,y);
  t:=y-n+1;
  if (t<=0)then begin
    writeln(-1);exit;
  end;
  if (int64(t)*t+n-1<x)then writeln(-1)else begin
    writeln(t);for i:=1 to n-1 do writeln(1);
  end;
end.