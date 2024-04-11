{$r-,q-,s-,i-,o+}
{$M 10000000}
const
  maxm=3000000;
var
  max2,kg,kst,j,ll,n,i,max,kmax:longint;
  res:int64;
  g,pred,last,qu,b,st,sum,a:array[0..maxm]of longint;
  procedure modify(x:longint);
    begin
      while (x<maxm)do begin
        inc(sum[x]);
        x:=x or (x-1)+1;
      end;
    end;
  function findsum(x:longint):longint;
    var
      res:longint;
    begin
      res:=0;
      while (x>0)do begin
        inc(res,sum[x]);
        x:=x and (x-1);
      end;
      findsum:=res;
    end;
begin
{  assign(input,'input.txt');reset(input);
  assign(output,'output.txt');rewrite(output);}
  read(n);
  for i:=1 to n do read(a[i]);
{  n:=1000000;
  for i:=1 to n do a[i]:=1; }
  max:=0;                   
  kmax:=0;
  kg:=0;
  fillchar(last,sizeof(last),$0);
  fillchar(pred,sizeof(pred),$0);
  for i:=1 to n do begin
    a[i+n]:=a[i];
    if (a[i]>max)then begin
      max:=a[i];
      kmax:=0;
    end;
    if (a[i]=max)then inc(kmax);
  end;
  if (kmax=1)then begin
    max2:=0;
    kmax:=0;
    for i:=1 to n do begin
      if (a[i]=max)then continue;
      if (a[i]>max2)then begin
        max2:=a[i];
        kmax:=0;
      end;
      if (a[i]=max2)then inc(kmax);
    end;
    res:=-kmax;
  end else res:=-(int64(kmax)*(kmax-1) div 2);
  for i:=1 to n+n do b[i]:=a[n+n+1-i];
  kst:=0;
  for i:=1 to n+n do begin
    while (kst>0)and(b[i]>=b[st[kst]])do dec(kst);
    if (kst=0)then ll:=1 else ll:=st[kst];
    inc(kst);st[kst]:=i;
    if (ll<=i-n)then ll:=i-n+1;
    if (i>n)then qu[n+n+1-i]:=n+n+1-ll;
  end;
  kst:=0;
  for i:=1 to n+n do begin
    while (kst>0)and(a[i]>=a[st[kst]])do dec(kst);
    if (kst=0)then ll:=1 else ll:=st[kst];
    inc(kst);st[kst]:=i;
    if (ll<=i-n)then ll:=i-n+1;
    inc(kg);g[kg]:=i;pred[kg]:=last[ll];last[ll]:=kg;
  end;
  for i:=1 to n do begin
    j:=last[i];
    while (j>0)do begin
      modify(g[j]);
      j:=pred[j];
    end;
    res:=res+findsum(qu[i]);
    res:=res-findsum(i-1);
  end;
  writeln(res-n);
end.