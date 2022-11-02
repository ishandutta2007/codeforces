{$r+,q+,s+,i+,o-}
uses
  math;

const
  inf=2000000000;

var
  k:array[0..500500]of longint;
  a:array[0..500500]of int64;
  m,ll,rr,i,s,n,q:longint;
  p,ct:int64;

  procedure qs(l,r:longint);
    var
      i,j,xx,tmp:longint;
      
    begin
      i:=l;j:=r;
      xx:=k[l+random(r-l+1)];
      while (i<=j)do begin
        while (xx>k[i])do inc(i);
        while (xx<k[j])do dec(j);
        if (I>j)then break;
        tmp:=k[i];k[i]:=k[j];k[j]:=tmp;
        tmp:=a[i];a[i]:=a[j];a[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<r)then qs(i,r);
      if (j>l)then qs(l,j);
    end;
    
  function bad(m:longint):boolean;
    var
      i,p,j:longint;
      
    begin
    for i:=1 to n do begin
      p:=1;
      for j:=1 to m-k[i] do begin
        p:=p*4;
        if (p>a[i])then break;
      end;
      if (p<a[i])then begin
        bad:=true;
        exit;
      end;
    end;    
    bad:=false;
    end;

begin
  read(n);
  for i:=1 to n do read(k[i],a[i]);
  qs(1,n);
  ll:=k[n]+1;rr:=inf;
  while (ll<rr-1)do begin
    m:=(int64(ll)+rr)div 2;
    if (bad(m))then ll:=m else rr:=m;
  end;
  if (bad(ll))then writeln(rr)else writeln(ll);
end.