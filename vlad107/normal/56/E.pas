{$r-,q-,s-,i-,o+}
var
  j,ll,rr,n,i,cr:longint;
  y,lg2,f,res,nom,x,h:array[0..1000000]of longint;
  q:array[0..200000,0..19]of longint;
  procedure qs(l,r:longint);
    var
      i,j,xx,tmp:longint;
    begin
      i:=l;j:=r;
      xx:=x[(i+j)shr 1];
      while (i<=j)do begin
        while (xx>x[i])do inc(i);
        while (xx<x[j])do dec(j);
        if (i>j)then break;
        tmp:=x[i];x[i]:=x[j];x[j]:=tmp;
        tmp:=h[i];h[i]:=h[j];h[j]:=tmp;
        tmp:=nom[i];nom[i]:=nom[j];nom[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<r)then qs(i,r);
      if (j>l)then qs(l,j);
    end;
  function fmax(l,r:longint):longint;
    var
      o:longint;
    begin
      o:=lg2[r-l+1];
      if (y[q[l][o]]>y[q[r-(1 shl o)+1][o]])
        then fmax:=q[l][o]
        else fmax:=q[r-(1 shl o)+1][o];
    end;
begin
  lg2[0]:=0;
  lg2[1]:=0;
  lg2[2]:=1;
  read(n);
  for i:=3 to n do
    lg2[i]:=lg2[i shr 1]+1;
  for i:=1 to n do read(x[i],h[i]);
  for i:=1 to n do nom[i]:=i;
  qs(1,n);
  fillchar(f,sizeof(f),$0);
  y[0]:=0;
  fillchar(q,sizeof(q),$0);
  for i:=1 to n do
    y[i]:=x[i]+h[i]-1;
  for i:=1 to n do
    q[i][0]:=i;
  for j:=1 to lg2[n] do
    for i:=1 to n-(1 shl (j))+1 do
      if (y[q[i][j-1]]>y[q[i+(1 shl (j-1))][j-1]])
        then q[i][j]:=q[i][j-1]
        else q[i][j]:=q[i+(1 shl (j-1))][j-1];
  f[n]:=1;
  for i:=n-1 downto 1 do
    if (y[i]<x[i+1])
      then f[i]:=1
      else begin
        ll:=i+1;rr:=n;
        while (ll<rr-1)do
          if (y[i]<x[(ll+rr)shr 1])
            then rr:=(ll+rr)shr 1
            else ll:=(ll+rr)shr 1;
        if (y[i]>=x[rr])then ll:=rr;
        j:=fmax(i+1,ll);
        f[i]:=f[j]+(j-i);
      end;
  for i:=1 to n do res[nom[i]]:=f[i];
  for i:=1 to n do write(res[i],' ');
end.