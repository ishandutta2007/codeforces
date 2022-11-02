var
  k1,k2,x,y,n,m,i:longint;

begin
  read(n,m);
  for i:=1 to n do begin
    read(x);
    if (x=-1)then inc(k1)else inc(k2);
  end;
  for i:=1 to m do begin
    read(x,y);
    if ((y-x)and 1=0)then writeln(0)else
    if ((y-x+1)div 2<=k1)and((y-x+1)div 2<=k2)then writeln(1)else
    writeln(0);
  end;
end.