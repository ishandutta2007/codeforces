var
  sa,a:array[0..500500]of int64;
  ct:int64;
  nom,mid,ans,ll,rr,n,k,i:longint;

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
  read(n,k);
  for i:=1 to n do read(a[i]);
  qs(1,n);
  for i:=1 to n do sa[i]:=sa[i-1]+a[i];
  ans:=0;
  for i:=1 to n do begin
    ll:=1;rr:=i;
    while (ll<rr-1)do begin
      mid:=(ll+rr)shr 1;
      ct:=sa[i-1]-sa[mid-1];
      ct:=a[i]*(i-mid)-ct;
      if (ct<=k)then rr:=mid else ll:=mid;
    end;
    ct:=sa[i-1]-sa[ll-1];
    ct:=a[i]*(i-ll)-ct;
    if (ct>k)then ll:=rr;
    if (i-ll+1>ans)then begin
      ans:=i-ll+1;
      nom:=a[i];
    end;
  end;
  writeln(ans,' ',nom);
end.