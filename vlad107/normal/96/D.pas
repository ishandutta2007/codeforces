{$r-,q-,s-,i-,o+}
const
  inf:int64=1000000000000000;
var
  ii,qb,qe,kg,n,m,i,j,ss,ff,x,y:longint;
  z:int64;
  q:array[0..1111111]of longint;
  t,c,pred,last,g:array[0..1005010]of longint;
  p:array[0..1005010]of int64;
  d:array[0..11111]of int64;
  gg:array[0..1111,0..1111]of int64;
begin
  read(n,m);
  read(ss,ff);
  for i:=1 to m do begin
    read(x,y,z);
    inc(kg);
    g[kg]:=y;
    p[kg]:=z;
    pred[kg]:=last[x];
    last[x]:=kg;
   
    inc(kg);
    g[kg]:=x;
    p[kg]:=z;
    pred[kg]:=last[y];
    last[y]:=kg;
  end;
  for i:=1 to n do read(t[i],c[i]);
  for i:=1 to n do begin
    qb:=0;qe:=1;
    q[1]:=i;
    for j:=1 to n do d[j]:=t[i]+1;
    d[i]:=0;
    while (qb<qe)do begin
      inc(qb);
      x:=q[qb];
      ii:=last[x];
      while (ii>0)do begin
        y:=g[ii];
        z:=p[ii];
        if (d[x]+z<d[y])then begin
          d[y]:=d[x]+z;
          inc(qe);
          q[qe]:=y;
        end;
        ii:=pred[ii];
      end;
    end;
    for j:=1 to n do
      if (j<>i)and(d[j]<=t[i])then gg[i][j]:=c[i] else gg[i][j]:=inf;
  end;
  kg:=0;
  fillchar(pred,sizeof(pred),$0);
  fillchar(last,sizeof(last),$0);
  for i:=1 to n do
    for j:=1 to n do
      if (gg[i][j]<>inf)then begin
        inc(kg);
        g[kg]:=j;
        p[kg]:=gg[i][j];
        pred[kg]:=last[i];
        last[i]:=kg;
      end;
  for i:=1 to n do d[i]:=inf;
  d[ss]:=0;
  qb:=0;qe:=1;
  q[1]:=ss;
  while (qb<qe)do begin
    inc(qb);
    x:=q[qb];
    ii:=last[x];
    while (ii>0)do begin
      y:=g[ii];
      z:=p[ii];
      if (d[x]+z<d[y])then begin
        d[y]:=d[x]+z;
        inc(qe);
        q[qe]:=y;
      end;
      ii:=pred[ii];
    end;
  end;
  if (d[ff]=inf)then d[ff]:=-1;
  writeln(d[ff]);
end.