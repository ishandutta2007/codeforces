var
  time,ans,sum:int64;
  tmp,n,i,j,qb,qe:longint;
  qq:int64;
  t,c:array[0..500500]of longint;
  a:array[0..500500]of longint;

begin
  read(n);
  for i:=1 to n do read(t[i],c[i]);
  qb:=1;qe:=0;sum:=0;
  for i:=1 to n do begin
    if (sum>ans)then ans:=sum;
    qq:=t[i]-t[i-1];
    while (qq>0)and(qb<=qe)do 
      if (qq>=a[qb])then begin
        dec(qq,a[qb]);
        dec(sum,a[qb]);
        a[qb]:=0;
        inc(qb);
      end else begin
        dec(a[qb],qq);
        dec(sum,qq);
        qq:=0;
      end;
    inc(qe);
    a[qe]:=c[i];
    inc(sum,a[qe]);
  end;
  if (sum>ans)then ans:=sum;
  writeln(t[n]+sum,' ',ans);
end.