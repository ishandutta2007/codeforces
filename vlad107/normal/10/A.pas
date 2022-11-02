var
  c,res,n,p1,t1,p2,t2,p3,i:longint;
  l,r:array[1..10000]of longint;
begin
  read(n,p1,p2,p3,t1,t2);
  for i:=1 to n do read(l[i],r[i]);
  res:=(r[1]-l[1])*p1;
  for i:=2 to n do begin
    inc(res,(r[i]-l[i])*p1);
    c:=l[i]-r[i-1];
    if (c>t1+t2)then begin
      inc(res,p1*t1+p2*t2+p3*(c-t1-t2));
      continue;
    end;
    if (c>t1)then begin
      inc(res,p1*t1+p2*(c-t1));
      continue;
    end;
    inc(res,p1*c);
  end;
  writeln(res);
end.