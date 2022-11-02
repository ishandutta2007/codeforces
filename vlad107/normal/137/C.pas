{$r-,q-,s-,i-,o+}
var         
  sum,a,b:array[0..500500]of longint;
  tmp,n,i,x,res,cr:longint;

  procedure qs(l,r:longint);
    var
      tmp,i,j,xx:longint;
    begin
      xx:=a[l+random(r-l+1)];
      i:=l;j:=r;
      while (i<=j)do begin
        while (xx>a[i])do inc(i);
        while (xx<a[j])do dec(j);
        if (i>j)then break;
        tmp:=a[i];a[i]:=a[j];a[j]:=tmp;
        tmp:=b[i];b[i]:=b[j];b[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<r)then qs(i,r);
      if (j>l)then qs(l,j);
    end;

begin
  randomize;
  read(n);
  for i:=1 to n do read(a[i],b[i]);
  qs(1,n);

  for i:=1 to n do a[i]:=i;
  for i:=1 to n do begin
    tmp:=a[i];a[i]:=b[i];b[i]:=tmp;
    a[i]:=-a[i];                  
  end;
  qs(1,n);

  fillchar(sum,sizeof(sum),$0);
  res:=0;
  for i:=1 to n do begin
    x:=b[i];
    cr:=0;
    while (x>0)do begin
      inc(cr,sum[x]);
      x:=x and (x-1);
    end;
    if (cr>0)then inc(res);
    x:=b[i];
    while (x<=n)do begin
      inc(sum[x]);
      x:=x or (x-1) + 1;
    end;
  end;
  writeln(res);
end.