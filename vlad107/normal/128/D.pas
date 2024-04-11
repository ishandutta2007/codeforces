var
  kol,b,a,deg:array[0..500500]of longint;
  n,m,i:longint;
  
  procedure qs(l,r:longint);
    var
      i,j,xx,tmp:longint;
      
    begin
      i:=l;j:=r;
      xx:=a[l+random(r-l+1)];
      while (i<=j)do begin
        while (xx>a[i])do inc(i);
        while (xx<a[j])do dec(j);
        if (i>j)then break;
        tmp:=a[i];a[i]:=a[j];a[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<r)then qs(i,r);
      if (j>l)then qs(l,j);
    end;
  
begin
  randomize;
  read(n);
  for i:=1 to n do read(a[i]);
  qs(1,n);
  for i:=2 to n do 
    if (a[i]>a[i-1]+1)then begin
      writeln('NO');
      exit;
    end;
  b[1]:=1;
  for i:=2 to n do
    if (a[i]=a[i-1])
      then b[i]:=b[i-1]
      else b[i]:=b[i-1]+1;
  for i:=1 to n do a[i]:=b[i];
  fillchar(kol,sizeof(kol),$0);
  for i:=1 to n do inc(kol[a[i]]);
  m:=a[n];
  for i:=1 to m do deg[i]:=kol[i]*2;
  for i:=2 to m do dec(deg[i],deg[i-1]);
  for i:=1 to m-1 do 
    if (deg[i]<=0)then begin
      writeln('NO');
      exit;
    end;
  if (deg[m]=0)
    then writeln('YES')
    else writeln('NO')
end.