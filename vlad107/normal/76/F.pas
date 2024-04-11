{$r-,q-,s-,i-,o+}
{$M 10000000}
const
  inf=maxlongint;
var
  ta,nom,mmax,a,b,x,t:array[0..200500]of longint;
  last,v,kl,j,r2,n,cr,res,i:longint;
  procedure qsta(l,r:longint);
    var
      nn,i,j,tmp,xx:longint;
    begin
      i:=l;j:=r;
      nn:=l+random(r-l+1);
      xx:=ta[nn];
      while (i<=j)do begin
        while (xx>ta[i])do inc(i);
        while (xx<ta[j])do dec(j);
        if (i>j)then break;
        tmp:=ta[i];ta[i]:=ta[j];ta[j]:=tmp;
        tmp:=nom[i];nom[i]:=nom[j];nom[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<r)then qsta(i,r);
      if (j>l)then qsta(l,j);
    end;
  procedure qsb(l,r:longint);
    var
      nn,xx,yy,i,j,tmp:longint;
    begin
      i:=l;j:=r;
      nn:=l+random(r-l+1);
      xx:=b[nn];
      yy:=a[nn];
      while (i<=j)do begin
        while (xx>b[i])or(xx=b[i])and(yy>a[i])do inc(i);
        while (xx<b[j])or(xx=b[j])and(yy<a[j])do dec(j);
        if (i>j)then break;
        tmp:=a[i];a[i]:=a[j];a[j]:=tmp;
        tmp:=b[i];b[i]:=b[j];b[j]:=tmp;
        tmp:=x[i];x[i]:=x[j];x[j]:=tmp;
        tmp:=t[i];t[i]:=t[j];t[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<r)then qsb(i,r);
      if (j>l)then qsb(l,j);
    end;
begin
  randomize;
  //assign(input,'input.txt');reset(input);
  //assign(output,'output.txt');rewrite(output);
  read(n);
  for i:=1 to n do read(x[i],t[i]);
  read(v);
  inc(n);
  t[n]:=0;
  x[n]:=0;
  for i:=1 to n do begin
    a[i]:=v*t[i]+x[i];
    b[i]:=v*t[i]-x[i];
    nom[i]:=i;
    ta[i]:=a[i];
  end;
  qsta(1,n);
  kl:=0;
  ta[0]:=inf;
  for i:=1 to n do begin
    if (ta[i]<>ta[i-1])then inc(kl);
    a[nom[i]]:=kl;
  end;
  qsb(1,n);
  for i:=1 to kl do mmax[i]:=-inf;
  res:=0;
  for i:=1 to n do begin
    if (t[i]=0)then continue;
    j:=a[i];
    cr:=-inf;
    while (j>0)do begin
      if (mmax[j]>cr)then cr:=mmax[j];
      j:=j and (j-1);
    end;
    if (cr<0)then cr:=0;
    inc(cr);
    if (cr>res)then res:=cr;
    j:=a[i];
    while (j<=kl)do begin
      if (cr>mmax[j])then mmax[j]:=cr;
      j:=j or (j-1)+1;
    end;
  end;
  r2:=res;
  res:=0;
  for i:=1 to kl do mmax[i]:=-inf;
  for i:=1 to n do 
    if (t[i]=0)then begin
      j:=a[i];
      while (j<=kl)do begin
        mmax[j]:=0;
        j:=j or (j-1)+1;
      end;
      last:=i;
      break;
    end;
  for i:=last+1 to n do begin
    j:=a[i];
    cr:=-inf;
    while (j>0)do begin
      if (mmax[j]>cr)then cr:=mmax[j];
      j:=j and (j-1);
    end;
    if (cr<0)then continue;
    inc(cr);
    if (cr>res)then res:=cr;
    j:=a[i];
    while (j<=kl)do begin
      if (cr>mmax[j])then mmax[j]:=cr;
      j:=j or (j-1)+1;
    end;
  end;  
  writeln(res,' ',r2);
  close(output);close(input);
end.