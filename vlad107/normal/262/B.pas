var
  res,n,m,i:longint;
  a:array[0..500500]of longint;
  
  procedure qs(l,r:longint);
    var
      tmp,i,j,xx:longint;
      
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
  read(n,m);
  for i:=1 to n do read(a[i]);
  qs(1,n);
  for i:=1 to n do begin
    if (m=0)then break;
    if (a[i]<=0)then begin
      a[i]:=-a[i];
      dec(m);
    end;
  end;
  if (m and 1=1)then begin
    qs(1,n);
    a[1]:=-a[1];
  end;
  res:=0;
  for i:=1 to n do inc(res,a[i]);
  writeln(res);
end.