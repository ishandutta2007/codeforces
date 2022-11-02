const
  base=1000000007;
  maxn=100000;

var
  qt,j,res,cr,jj,kt,i,x,n:longint;
  t,a:array[0..500500]of longint;

  function pow(x,y:longint):longint;
    var
      res,cr:longint;
      
    begin
      res:=1;
      cr:=x;
      while (y>0)do begin
        if (y and 1=1)then res:=int64(res)*cr mod base;
        cr:=int64(cr)*cr mod base;
        y:=y shr 1;
      end;
      pow:=res;
    end;
    
  procedure qs(l,r:longint);
    var
      tmp,xx,i,j:longint;
      
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

begin
//  assign(input,'input.txt');reset(input);
  randomize;
  read(n);
  for i:=1 to n do begin
    read(x);
    inc(a[x]);
  end;
  for i:=1 to maxn do inc(a[i],a[i-1]);
  res:=0;
  for i:=1 to maxn do begin
    kt:=0;
    jj:=1;
    while (jj*jj<=i)do begin
      if (i mod jj=0)then begin
        inc(kt);
        t[kt]:=jj;
        if (jj*jj<>i)then begin
          inc(kt);
          t[kt]:=i div jj;
        end;
      end;
      inc(jj);
    end;
    qs(1,kt);
    cr:=1;
    for j:=2 to kt do begin
      cr:=int64(cr)*pow(j-1,a[t[j]-1]-a[t[j-1]-1]) mod base;
    end;
    j:=a[maxn]-a[i-1];
    qt:=pow(kt,j)-pow(kt-1,j);
    if (qt<0)then inc(qt,base);
    cr:=int64(cr)*qt mod base;
    inc(res,cr);
    if (res>=base)then dec(res,base);
  end;
  writeln(res);
end.