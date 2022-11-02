{$r-,q-,s-,i-,o+}
const
  base=1000000007;
var
  ss,ff,sum,f,last,pred,g,a:array[0..500500]of longint;
  ii,min,kh,n,m,i,j,ka,kb:longint;
  procedure qs(l,r:longint);
    var
      tmp,xx,i,j:longint;
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
  function findh(x:longint):longint;
    var
      l,r:longint;
    begin
      l:=1;r:=ka;
      while (l<r-1)do
        if (x>a[(l+r)shr 1])
          then l:=(l+r)shr 1
          else r:=(l+r)shr 1;
      if (x=a[l])then findh:=l else findh:=r;
    end;
begin
  randomize;
  read(m,n);
  ka:=2;a[1]:=0;a[2]:=m;
  for i:=1 to n do begin
    read(ss[i],ff[i]);
    inc(ka);a[ka]:=ss[i];
    inc(ka);a[ka]:=ff[i];
  end;
  qs(1,ka);
  kb:=1;
  for i:=2 to ka do
    if (a[i]<>a[kb])then begin
      inc(kb);
      a[kb]:=a[i];
    end;
  m:=kb;
  ka:=kb;
  kh:=0;
  for i:=1 to n do begin
    ss[i]:=findh(ss[i]);
    ff[i]:=findh(ff[i]);
    inc(kh);
    g[kh]:=ss[i];
    pred[kh]:=last[ff[i]];
    last[ff[i]]:=kh;
  end;
  f[0]:=0;
  f[1]:=1;
  sum[1]:=1;
  sum[0]:=0;
  for i:=2 to m do begin
    ii:=last[i];
    f[i]:=0;
    while (ii>0)do begin
      min:=g[ii];
      f[i]:=f[i]+sum[i-1]-sum[min-1];
      if (f[i]<0)then f[i]:=f[i]+base;
      f[i]:=f[i] mod base;
      ii:=pred[ii];
    end;
    sum[i]:=(sum[i-1]+f[i])mod base;
  end;
  writeln(f[m]);
end.