var
  n,t,x,y,k1,t1,k2,t2,i:longint;

begin
  read(n);
  k1:=0;k2:=0;
  t1:=0;t2:=0;
  for i:=1 to n do begin
    read(t,x,y);
    if (t=1)then begin
      inc(k1,10);
      inc(t1,x);
    end;
    if (t=2)then begin
      inc(k2,10);
      inc(t2,x);
    end;
  end;
  if (t1+t1>=k1)then writeln('LIVE')else writeln('DEAD');
  if (t2+t2>=k2)then writeln('LIVE')else writeln('DEAD');
end.