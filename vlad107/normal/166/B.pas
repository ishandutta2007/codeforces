{$r-,q-,s-,i-,o+}
var
  xx,yy,q1,q2:int64;
  s1,f1,s2,f2,kt,n1,n2,n3,n4,i,n,tt:longint;
  x,y,tx,ty:array[0..500500]of int64;
  
  function side(x3,y3,x1,y1,x2,y2:int64):int64;
    begin
      side:=(y2-y1)*(x3-x1)+(x1-x2)*(y3-y1);
    end;

  function find(xx,yy:int64;ll,rr:longint):int64;
    var
      mid:longint;
      
    begin
      dec(rr);
      while (ll<rr-1)do begin
        mid:=(ll+rr)shr 1;
        if (yy<ty[mid])
          then rr:=mid
          else ll:=mid;
      end;
      if (yy>=ty[ll])and(yy<=ty[rr])
        then find:=side(xx,yy,tx[ll],ty[ll],tx[rr],ty[rr])
        else find:=side(xx,yy,tx[rr],ty[rr],tx[rr+1],ty[rr+1]);
    end;

begin
  read(n);
  for i:=1 to n do read(x[i],y[i]);
  for i:=n+1 to n+n do x[i]:=x[i-n];
  for i:=n+1 to n+n do y[i]:=y[i-n];
  n1:=1;//miny,minx
  n2:=1;//maxy,minx
  n3:=1;//maxy,maxx
  n4:=1;//miny,maxx
  for i:=2 to n do begin
    if (y[i]<y[n1])or(y[i]=y[n1])and(x[i]<x[n1])then n1:=i;
    if (y[i]>y[n2])or(y[i]=y[n2])and(x[i]<x[n2])then n2:=i;
    if (y[i]>y[n3])or(y[i]=y[n3])and(x[i]>x[n3])then n3:=i;
    if (y[i]<y[n4])or(y[i]=y[n4])and(x[i]>x[n4])then n4:=i;
  end;
  if (n2<n1)then inc(n2,n);
  if (n4<n3)then inc(n4,n);
  kt:=0;
  for i:=n1 to n2 do begin
    inc(kt);
    tx[kt]:=x[i];
    ty[kt]:=y[i];
  end;
  s1:=1;f1:=kt;
  for i:=n4 downto n3 do begin
    inc(kt);
    tx[kt]:=x[i];
    ty[kt]:=y[i];
  end;
  s2:=f1+1;f2:=kt;
  read(tt);
  while (tt>0)do begin
    dec(tt);
    read(xx,yy);
    if (yy<=y[n1])or(yy>=y[n2])then begin
      writeln('NO');
      exit;
    end;
    q1:=find(xx,yy,s1,f1);
    q2:=find(xx,yy,s2,f2);
    if (q1<0)and(q2>0)then continue;
    if (q1>0)and(q2<0)then continue;
    writeln('NO');
    exit;
  end;
  writeln('YES');
end.