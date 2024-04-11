{$r-,q-,s-,i-,o+}
var
  l,n,cr:int64;
  it,i:longint;
  a:array[1..222222] of int64;
  x,ll,rr:extended;

  procedure qs(l,r:longint);
    var
      xx,tmp:int64;
      i,j:longint;

    begin
      i:=l;j:=r;
      xx:=a[(i+j)shr 1];
      while (i<=j) do begin
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
  read(n);
  for i:=1 to n do read(a[i]);
  qs(1,n);
  ll:=0;rr:=2*1e9+1;
  a[n+1]:=1000000000000;
  for it:=1 to 100 do begin
    x:=(ll+rr);
    l:=1;
    cr:=1;
    for i:=2 to n do
      if (a[l]+x<a[i])then begin
        inc(cr);
        l:=i;
      end;
    if (cr>3)then ll:=x/2 else rr:=x/2;
  end;
  x:=(ll+rr);
  writeln(x/2:0:10);
  l:=1;
  x:=x+1e-10;
  cr:=0;
  for i:=2 to n+1 do
    if (a[l]+x<a[i])then begin
      inc(cr);
      write(a[l]+(x/2):0:10,' ');
      l:=i;
    end;
  for i:=1 to 3-cr do write('0 ');
  writeln;
end.