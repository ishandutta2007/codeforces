var
  n,k,i:longint;
  a:array[0..500500]of longint;

  procedure qs(l,r:longint);
    var
      i,j,xx,tmp:longint;

    begin
      i:=l;j:=r;
      xx:=a[l+random(r-l+1)];
      while (i<=j)do begin
        while (Xx>a[i])do inc(i);
        while (xx<A[j])do dec(j);
        if (i>j)then break;
        tmp:=a[i];a[i]:=a[j];a[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<r)Then qs(i,r);
      if (j>l)then qs(l,j);
    end;

begin
  read(n,k);
  for i:=1 to n do read(a[i]);
  qs(1,n);
  if (k>n)then begin
    writeln(-1);
    exit;
  end;
  writeln(a[n-k+1],' ',a[n-k+1]);
end.