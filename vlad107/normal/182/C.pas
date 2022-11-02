{$r-,q-,s-,i-,o+}
const
  inf:int64=1000000000000000000;

var
  s1,s2:array[0..500500]of int64;
  t,a,b,nom:array[0..500500]of longint;
  cr,ans,sum:int64;
  k,ll,rr,kt,mid,n,i,len:longint;

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
        tmp:=nom[i];nom[i]:=nom[j];nom[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<r)then qs(i,r);
      if (j>l)then qs(l,j);
    end;
    
  procedure add1(x,val:longint);
    begin
      while (x<=kt)do begin
        s1[x]:=s1[x]+val;
        x:=x or (x-1)+1;
      end;
    end;
    
  procedure add2(x,val:longint);
    begin
      while (x<=kt)do begin
        s2[x]:=s2[x]+val;
        x:=x or (x-1)+1;
      end;
    end;
    
  function fsum1(x:longint):int64;
    var
      res:int64;
      
    begin
      res:=0;
      while (x>0)do begin
        res:=res+s1[x];
        x:=x and(x-1);
      end;
      fsum1:=res;
    end;
    
  function fsum2(x:longint):int64;
    var
      res:int64;
      
    begin
      res:=0;
      while (x>0)do begin
        res:=res+s2[x];
        x:=x and(x-1);
      end;
      fsum2:=res;
    end;
    
begin
  read(n,len);
  for i:=1 to n do read(a[i]);
  read(k);
  
  kt:=0;
  for i:=1 to n do 
    if (a[i]<0)then begin
      inc(kt);
      t[kt]:=a[i];
      nom[kt]:=i;
    end;
  qs(1,kt);
  for i:=1 to kt do b[nom[i]]:=i;
  sum:=0;
  for i:=1 to len do begin
    sum:=sum+a[i];
    if (a[i]<0)then begin
      add1(b[i],+1);
      add2(b[i],a[i]);
    end;
  end;
  ans:=-inf;
  for i:=len to n do begin
    ll:=0;rr:=kt;
    while (ll<rr-1)do begin
      mid:=(ll+rr)shr 1;
      if (fsum1(mid)>k)
        then rr:=mid
        else ll:=mid;
    end;
    if (fsum1(rr)<=k)
      then cr:=sum-2*fsum2(rr)
      else cr:=sum-2*fsum2(ll);
    if (abs(cr)>ans)then ans:=abs(cr);
    if (i=n)then break;
    sum:=sum+a[i+1];
    if (a[i+1]<0)then begin
      add1(b[i+1],+1);
      add2(b[i+1],a[i+1]);
    end;
    sum:=sum-a[i-len+1];
    if (a[i-len+1]<0)then begin
      add1(b[i-len+1],-1);
      add2(b[i-len+1],-a[i-len+1]);
    end;
  end;

  for i:=1 to n do a[i]:=-a[i];
  kt:=0;
  for i:=1 to n do 
    if (a[i]<0)then begin
      inc(kt);
      t[kt]:=a[i];
      nom[kt]:=i;
    end;
  qs(1,kt);
  for i:=1 to kt do b[nom[i]]:=i;
  sum:=0;
  fillchar(s1,sizeof(s1),$0);
  fillchar(s2,sizeof(s2),$0);
  for i:=1 to len do begin
    sum:=sum+a[i];
    if (a[i]<0)then begin
      add1(b[i],+1);
      add2(b[i],a[i]);
    end;
  end;
  for i:=len to n do begin
    ll:=0;rr:=kt;
    while (ll<rr-1)do begin
      mid:=(ll+rr)shr 1;
      if (fsum1(mid)>k)
        then rr:=mid
        else ll:=mid;
    end;
    if (fsum1(rr)<=k)
      then cr:=sum-2*fsum2(rr)
      else cr:=sum-2*fsum2(ll);
    if (abs(cr)>ans)then ans:=abs(cr);
    if (i=n)then break;
    sum:=sum+a[i+1];
    if (a[i+1]<0)then begin
      add1(b[i+1],+1);
      add2(b[i+1],a[i+1]);
    end;
    sum:=sum-a[i-len+1];
    if (a[i-len+1]<0)then begin
      add1(b[i-len+1],-1);
      add2(b[i-len+1],-a[i-len+1]);
    end;
  end;

  writeln(ans);
end.