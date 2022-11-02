{$r-,q-,s-,i-,o+}
var
  u1,u2:array[0..500500]of boolean;
  ii,qb,qe,x,y,i,n,m,kg:longint;
  last,g,pred,ss,ff,a,q:array[0..500500]of longint;

begin
  read(n,m);
  for i:=1 to n do read(a[i]);
  for i:=1 to m do read(ss[i],ff[i]);
  kg:=0;
  fillchar(last,sizeof(last),$0);
  fillchar(pred,sizeof(pred),$0);
  fillchar(u1,sizeof(u1),false);
  fillchar(u2,sizeof(u2),false);
  for i:=1 to m do begin
    x:=ss[i];y:=ff[i];
    inc(kg);g[kg]:=y;pred[kg]:=last[x];last[x]:=kg;
  end;
  qb:=0;qe:=0;
  for i:=1 to n do 
    if (a[i]=1)then begin
      inc(qe);q[qe]:=i;
      u1[i]:=true;
    end;
  while (qb<qe)do begin
    inc(qb);x:=q[qb];
    ii:=last[x];
    while (ii>0)do begin
      y:=g[ii];
      if (not u1[y])then begin
        u1[y]:=true;
        inc(qe);q[qe]:=y;
      end;
      ii:=pred[ii];
    end;
  end;
  kg:=0;
  fillchar(last,sizeof(last),$0);
  fillchar(pred,sizeof(pred),$0);
  for i:=1 to m do begin
    x:=ff[i];y:=ss[i];
    inc(kg);g[kg]:=y;pred[kg]:=last[x];last[x]:=kg;
  end;  
  qb:=0;qe:=0;
  for i:=1 to n do 
    if (a[i]=2)then begin
      inc(qe);q[qe]:=i;
      u2[i]:=true;
    end;
  while (qb<qe)do begin
    inc(qb);x:=q[qb];
    ii:=last[x];
    while (ii>0)do begin
      y:=g[ii];
      if (not u2[y])then begin
        u2[y]:=true;
        if (a[y]<>1)then begin
          inc(qe);q[qe]:=y;
        end;
      end;
      ii:=pred[ii];
    end;
  end;
  for i:=1 to n do 
    if (u1[i])and(u2[i])
      then writeln(1)
      else writeln(0);
end.