{$r-,q-,s-,i-,o+}
const
  inf=1100000000;

var
  z,kg,ii,ct,qb,qe,n,m,i,j,x,y:longint;
  p,d,next,ss,ff,time,last,pred,g:array[0..500500]of longint;
  q:array[0..2000000]of longint;
  
  function find(l,r,x:longint):longint;
    begin
      if (l>r)then begin
        find:=x;
        exit;
      end;
      while (l<r-1)do 
        if (time[(l+r)shr 1]>x)
          then r:=(l+r)shr 1
          else l:=(l+r)shr 1;
      if (time[l]=x)
        then find:=next[l]
        else
      if (time[r]=x)
        then find:=next[r]
        else find:=x;
    end;

begin
  read(n,m);
  for i:=1 to m do begin
    read(x,y,z);
    inc(kg);g[kg]:=y;p[kg]:=z;pred[kg]:=last[x];last[x]:=kg;
    inc(kg);g[kg]:=x;p[kg]:=z;pred[kg]:=last[y];last[y]:=kg;
  end;
  ss[0]:=0;ff[0]:=0;
  for i:=1 to n do begin
    read(x);
    ss[i]:=ff[i-1]+1;
    ff[i]:=ss[i]+x-1;
    for j:=ss[i] to ff[i] do read(time[j]);
    next[ff[i]]:=time[ff[i]]+1;
    for j:=ff[i]-1 downto ss[i]do 
      if (time[j]+1=time[j+1])
        then next[j]:=next[j+1]
        else next[j]:=time[j]+1;
  end;
  for i:=2 to n do d[i]:=inf;
  d[1]:=0;
  qb:=0;qe:=1;
  q[1]:=1;
  while (qb<qe)do begin
    inc(qb);
    x:=q[qb];
    ii:=last[x];
    while (ii>0)do begin
      y:=g[ii];
      ct:=find(ss[x],ff[x],d[x])+p[ii];
      if (ct<d[y])then begin
        d[y]:=ct;
        inc(qe);
        q[qe]:=y;
      end;
      ii:=pred[ii];
    end;
  end;
  if (d[n]=inf)then d[n]:=-1;
  writeln(d[n]);
end.