var
  n,x,i,ans:longint;
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
      if (i<r)then qs(i,r);
      if (j>l)then qs(l,j);
    end;

begin
  randomize;
  read(n,x);
  for i:=1 to n do read(a[i]);
  ans:=0;
  while (true)do begin
    qs(1,n);
    if (a[(n+1)shr 1]=x)then break;
    inc(ans);
    inc(n);a[n]:=x;
  end;
  writeln(ans);
end.