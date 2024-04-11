var
  ans,ct:int64;
  t,n,i:longint;
  u,a:array[0..2002000]of longint;

  procedure qs(l,r:longint);
    var
      i,j,tmp,xx:longint;
      
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
  t:=1;
  while (t<=n)do begin
    inc(u[n-t+1]);
    t:=t*4;
  end;
  ct:=0;
  for i:=1 to n do begin
    inc(ct,u[i]);
    ans:=ans+int64(ct)*a[i];
  end;
  writeln(ans);
end.