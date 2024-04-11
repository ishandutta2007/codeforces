var
  i,j,x,n:longint;
  k,ck:int64;
  a:array[0..500500]of longint;
  
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
      if (i<r)Then qs(i,r);
      if (j>l)then qs(l,j);
    end;

begin
  randomize;
  read(n,k);
  for i:=1 to n do read(a[i]);
  qs(1,n);
  i:=1;
  while (true)do begin
    j:=i;
    while (j<=n)and(a[i]=a[j])do inc(j);
    ck:=int64(j-i)*n;
    if (ck<k)then begin
      k:=k-ck;
      i:=j;
      continue;
    end;
    write(a[i],' ');
    x:=j-i;
    for i:=1 to n do 
      if (x<k)then k:=k-x else begin
        writeln(a[i]);
        exit;
      end;
  end;
end.