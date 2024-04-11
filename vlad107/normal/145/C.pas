{$r-,q-,s-,i-,o+}
const
  base=1000000007;
  maxn=100500;
var
  kl,kn,n,k,i,j:longint;
  ff:array[0..1111,0..1111]of int64;
  res,cr:int64;
  f,g:array[0..500500]of int64;
  rt,a,t:array[0..500500]of longint;

  function luck(x:longint):boolean;
    begin
      while (x>0)do begin
        if (x mod 10<>4)and(x mod 10<>7)then begin
          luck:=false;
          exit;
        end;
        x:=x div 10;
      end;
      luck:=true;
    end;

  procedure qs(l,r:longint);
    var
      i,j,xx,tmp:longint;

    begin
      i:=l;j:=r;
      xx:=t[l+random(r-l+1)];
      while (i<=j)do begin
        while (xx>t[i])do inc(i);
        while (xx<t[j])do dec(j);
        if (i>j)then break;
        tmp:=t[i];t[i]:=t[j];t[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<r)then qs(i,r);
      if (j>l)then qs(l,j);
    end;

  function pow(x,y:longint):int64;
    var
      tt:int64;

    begin
      if (y=0)then begin pow:=1;exit; end;
      if (y mod 2=0)then begin
        tt:=pow(x,y div 2);
        tt:=int64(tt)*tt mod base;
        pow:=tt;
      end else
      if (y mod 2=1)then pow:=int64(pow(x,y-1))*x mod base;
    end;

  function cc(n,k:longint):int64;
    var
      cr:int64;

    begin
      if (k>n)then begin
        cc:=0;
        exit;
      end;
      cr:=f[n]*g[k]mod base;
      cr:=cr*g[n-k] mod base;
      cc:=cr;
    end;

begin
  randomize;
  read(n,k);
  kl:=0;kn:=0;

  for i:=1 to n do begin
    read(a[i]);
    if (luck(a[i]))then begin
      inc(kl);t[kl]:=a[i];
    end else inc(kn);
  end;
  if (kl>0)then qs(1,kl);

  if (kl>0)then begin
    j:=1;rt[1]:=1;
    for i:=2 to kl do
      if (t[i]<>t[j])then begin
        inc(j);
        t[j]:=t[i];
        rt[j]:=1;
      end else inc(rt[j]);
    kl:=j;
  end;

  f[0]:=1;
  for i:=1 to maxn do f[i]:=f[i-1]*i mod base;
  for i:=0 to maxn do g[i]:=pow(f[i],base-2);

  fillchar(ff,sizeof(ff),$0);
  ff[1][0]:=1;
  for i:=1 to kl do
    for j:=0 to kl do begin
      ff[i+1][j]:=(ff[i+1][j]+ff[i][j])mod base;
      if (j<kl)
        then ff[i+1][j+1]:=(ff[i+1][j+1]+(int64(ff[i][j])*rt[i] mod base))mod base;
    end;

  res:=0;
  for i:=0 to kl do begin
    cr:=ff[kl+1][i];
    j:=k-i;
    cr:=(cr*cc(kn,j))mod base;
    res:=(res+cr)mod base;
  end;
  writeln(res);
end.