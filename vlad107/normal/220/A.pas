var
  n,i,kt:longint;
  a,b:array[0..500500]of longint;
  
  procedure qs(l,r:longint);
    var
      i,j,tmp,xx:longint;
      
    begin
      i:=l;j:=r;
      xx:=a[l+random(r-l+1)];
      while (i<=j)do begin
        while (xx>a[i])do inc(i);
        while (xx<A[j])do dec(j);
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
  for i:=1 to n do b[i]:=a[i];
  qs(1,n);
  kt:=0;
  for i:=1 to n do
    if (a[i]<>b[i])then inc(kt);
  if (kt<=2)
    then writeln('YES')
    else writeln('NO');
end.