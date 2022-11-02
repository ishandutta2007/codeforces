{$r-,q-,s-,i-,o+}
var
  kb,tt,n,i:longint;
  bn,a,b,o,nom:array[0..500500]of longint;
  res:array[0..500500]of boolean;
  procedure qs(l,r:longint);
    var
      i,j,xx,tmp,yy:longint;
    begin
      i:=l;j:=r;
      xx:=a[(i+j)shr 1];
      yy:=o[(i+j)shr 1];
      while (i<=j)do begin
        while (xx>a[i])or(xx=a[i])and(yy>o[i])do inc(i);
        while (xx<a[j])or(xx=a[j])and(yy<o[j])do dec(j);
        if (i>j)then break;
        tmp:=a[i];a[i]:=a[j];a[j]:=tmp;
        tmp:=o[i];o[i]:=o[j];o[j]:=tmp;
        tmp:=nom[i];nom[i]:=nom[j];nom[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<r)then qs(i,r);
      if (j>l)then qs(l,j);
    end;
begin
  read(tt);
  while (tt>0)do begin
    dec(tt);
    read(n);
    n:=2*n-1;
    for i:=1 to n do read(a[i],o[i]);
    for i:=1 to n do nom[i]:=i;
    for i:=1 to n do res[i]:=false;
    qs(1,n);
    kb:=0;
    for i:=1 to n do
      if (kb>0)and(b[kb]<=o[i])then begin
        res[nom[i]]:=true;
        dec(kb);
      end else begin
        inc(kb);
        b[kb]:=o[i];
        bn[kb]:=nom[i];
      end;
    i:=1;
    while (i<=kb)do begin
      res[bn[i]]:=true;
      inc(i,2);
    end;
    writeln('YES');
    for i:=1 to n do
      if (res[i])then write(i,' ');
    writeln;
  end;
end.