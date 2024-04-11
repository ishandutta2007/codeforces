var
  t1,t2,t3,t4,n,m,k,i,x,y:longint;
begin
  read(n,m,k);
  for i:=1 to k do begin
    read(x,y);
    t1:=abs(x-1);
    t2:=abs(y-1);
    t3:=abs(n-x);
    t4:=abs(m-y);
    if (t1<5)or(t2<5)or(t3<5)or(t4<5)then begin
      writeln('YES');
      exit;
    end;
  end;
  writeln('NO');
end.