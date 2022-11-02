{$r-,q-,s-,i-,o+}
const
  inf:int64=1000000000000000000;

var
  res,cr:int64;
  i,j,n,m,x,t1,t2,dt,c:longint;

  procedure check(k:longint);
    var
      ur:int64;
      mk:longint;
      
    begin
      if (k<1)then exit;
      ur:=int64(k)*c;
      mk:=(m+k-1)div k;
      if (mk>dt)
        then ur:=ur+int64(m-(m mod mk))*x;
      if (m mod mk>dt)
        then ur:=ur+int64(m mod mk)*x;
      if (ur<cr)then cr:=ur;
    end;

begin
  read(n,m);  
  res:=0;
  for i:=1 to n do begin
    read(t1,t2,x,c);
    dt:=t2-t1;
    if (dt<0)then dt:=0;
    cr:=inf;
    check(1);
    if (dt>0)then 
      for j:=0 to 10 do check((m+dt-1)div dt+j);
    check(m);
    res:=res+cr;
  end;
  writeln(res);
end.