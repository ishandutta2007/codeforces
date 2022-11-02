{$r-,q-,s-,i-,o+}
var
  j,n,i,last:longint;
  kol,k:int64;
  all0:boolean;
  a:array[0..55]of longint;
  st2:array[0..55]of int64;

  procedure rec(x,y,q:longint);
    begin
      if (y<x)then begin
        kol:=kol+1;
        exit;
      end;
      if (x=y)then begin
        if (q=1)then kol:=kol+ord(a[x]<>1) else
        if (a[x]<>-1)then kol:=kol+1 else
        kol:=kol+2;
        exit;
      end;

      if (a[x]=-1)then begin
        a[x]:=0;
        a[y]:=a[x] xor q;
        rec(x+1,y-1,q);

        a[x]:=1;
        a[y]:=a[x] xor q;
        rec(x+1,y-1,q);

        a[x]:=-1;a[y]:=-1;

        kol:=kol+st2[y-x-1];
        exit;
      end;

      if (a[y]<>-1)then begin
        if (a[y] xor q=a[x])then rec(x+1,y-1,q) else
        if (a[y] xor q>a[x])then kol:=kol+1;
        exit;
      end;

      a[y]:=a[x] xor q;
      rec(x+1,y-1,q);
      a[y]:=-1;

      if (a[x]=0)then kol:=kol+st2[y-last-1];
    end;

begin
  read(n,k);

  fillchar(a,sizeof(a),$FF);
  a[1]:=0;

  st2[0]:=1;
  for i:=1 to n do st2[i]:=st2[i-1]+st2[i-1];

  kol:=0;
  rec(2,n-1,0);
  rec(2,n-1,1);
  kol:=kol-1;

  if (k>kol)then begin
    writeln(-1);
    exit;
  end;

  all0:=true;

  for i:=2 to n-1 do begin

    kol:=0;
    a[i]:=0;
    last:=i;
    rec(2,n-1,0);
    rec(2,n-1,1);
    if (all0)then kol:=kol-1;

    if (k>kol)then begin
      a[i]:=1;
      k:=k-kol;
      all0:=false;
    end else a[i]:=0;

  end;
  for i:=1 to n-1 do write(a[i]);
  a[n]:=0;
  i:=1;
  j:=n;
  while (i<=j)and(a[i]=a[j])do begin
    inc(i);dec(j);
  end;
  if ((i>j)or(a[i]<a[j]))and(not all0)
    then writeln(k-1)
    else writeln(1);
end.