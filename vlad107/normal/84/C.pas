{$r-,q-,s-,i-,o+}
var
  ll,rr,n,m,i,j:longint;
  w,nom,x0,x,y,r:array[0..500500]of longint;
  procedure qs(ll,rr:longint);
    var
      i,j,xx,tmp:longint;
    begin
      i:=ll;j:=rr;
      xx:=x0[(i+j)shr 1];
      while (i<=j)do begin
        while (xx>x0[i])do inc(i);
        while (xx<x0[j])do dec(j);
        if (i>j)then break;
        tmp:=x0[i];x0[i]:=x0[j];x0[j]:=tmp;
        tmp:=r[i];r[i]:=r[j];r[j]:=tmp;
        tmp:=nom[i];nom[i]:=nom[j];nom[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<rr)then qs(i,rr);
      if (j>ll)then qs(ll,j);
    end;
begin
  read(n);
  for i:=1 to n do read(x0[i],r[i]);
  for i:=1 to n do nom[i]:=i;
  qs(1,n);
  read(m);
  fillchar(w,sizeof(w),$FF);
  for i:=1 to m do begin
    read(x[i],y[i]);
    ll:=1;rr:=n;
    while (ll<rr-1)do 
      if (x[i]<x0[(ll+rr)shr 1])
        then rr:=(ll+rr)shr 1
        else ll:=(ll+rr)shr 1;
    if ((x[i]-x0[ll])*(x[i]-x0[ll])+y[i]*y[i]<=r[ll]*r[ll])and(w[nom[ll]]<0)then w[nom[ll]]:=i;
    if ((x[i]-x0[rr])*(x[i]-x0[rr])+y[i]*y[i]<=r[rr]*r[rr])and(w[nom[rr]]<0)then w[nom[rr]]:=i;
  end;
  j:=n;
  for i:=1 to n do
    if (w[i]<0)then dec(j);
  writeln(j);
  for i:=1 to n do write(w[i],' ');
  writeln;
end.