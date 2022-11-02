{$r-,q-,s-,i-,o+}
var
  base,res,n,i,j:longint;
  f,a,b:array[0..500500]of longint;
  
  procedure qs(l,r:longint);
    var
      nn,i,j,xx,yy,tmp:longint;
      
    begin
      i:=l;j:=r;
      nn:=l+random(r-l+1);
      xx:=a[nn];
      yy:=b[nn];
      while (i<=j)do begin
        while (xx>a[i])or(xx=a[i])and(yy>b[i])do inc(i);
        while (xx<a[j])or(xx=a[j])and(yy<b[j])do dec(j);
        if (i>j)then break;
        tmp:=a[i];a[i]:=a[j];a[j]:=tmp;
        tmp:=b[i];b[i]:=b[j];b[j]:=tmp;
        inc(i);dec(j);
      end;
      if (I<r)then qs(i,r);
      if (j>l)then qs(l,j);
    end;
  
  function c(n,k:longint):longint;
    begin
      if (k=1)then c:=n mod base else
      c:=(int64(n)*(n-1)div 2)mod base;
    end;

begin
  read(n);
  for i:=1 to n do begin
    read(a[i]);b[i]:=i;
  end;
  for i:=n+1 to n+n do begin
    read(a[i]);
    b[i]:=i-n;
  end;
  read(base);
  qs(1,n+n);
  res:=1;
  n:=n+n;
  for i:=n downto 1 do 
    if (i=n)or(a[i]<>a[i+1])then f[i]:=1 else 
    f[i]:=f[i+1]+1;
  i:=1;
  while (i<=n)do begin
    j:=i;
    while (j<=n)and(a[j]=a[i])and(b[j]=b[i])do inc(j);
    dec(j);
    res:=int64(res)*c(f[i],j-i+1)mod base;
    i:=j+1;
  end;
  writeln(res mod base);
end.