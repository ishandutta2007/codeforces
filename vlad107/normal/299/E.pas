{$r-,q-,s-,i-,o+}
var
  x,n,m,a,b,c,ab,ac,bc:int64;
  i,j,kp,ans:longint;
  p:array[0..500500]of int64;
begin
  read(n);
  if (n mod 3<>0)then begin
    writeln(0);
    exit;
  end;
  n:=n div 3;
  ans:=0;
  x:=1;
  kp:=0;
  while ((x+1)*(x+1)<=n)do begin
    x:=x+1;
    if (n mod x=0)then begin
      inc(kp);
      p[kp]:=x;
    end;
  end;
  i:=0;
  while (i+1<=kp)and((p[i+1])*(p[i+1])*(p[i+1])<=n)do begin
    inc(i);
    ab:=p[i];
    if (n mod ab<>0)then continue;
    m:=n div ab;
    j:=i-1;
    while (j+1<=kp)and(p[j+1]*p[j+1]<=m)do begin
      inc(j);
      ac:=p[j];
      if (m mod ac<>0)then continue;
      bc:=m div ac;
      a:=ab+ac-bc;
      b:=bc+ab-ac;
      c:=bc+ac-ab;
      if (a<2)or(b<2)or(c<2)then continue;
      if (a and 1=1)then continue;
      if (a=b)and(a=c)then inc(ans) else
      if (a=b)or(a=c)or(b=c)then inc(ans,3) else
      inc(ans,6);
    end;
  end;
  writeln(ans);
end.