{$r-,q-,s-,i-,o+}
uses
  math;

var
  l,r,i,n:longint;
  inv,ct,ans,k:int64;
  a:array[0..200500]of longint;
  ta:array[0..18,0..200500]of longint;

  procedure rec(x,l,r:longint);
    var
      mid,i,j1,j2:longint;
      
    begin
      if (l=r)then begin
        ta[x][l]:=a[l];
        exit;
      end;
      mid:=(l+r)shr 1;
      rec(x+1,l,mid);
      rec(x+1,mid+1,r);
      j1:=l;j2:=mid+1;
      for i:=l to r do 
        if (j2>r)or((j1<=mid)and(ta[x+1][j1]<ta[x+1][j2]))then begin
          ta[x][i]:=ta[x+1][j1];
          inc(j1);
        end else begin
          ta[x][i]:=ta[x+1][j2];
          inc(j2);
        end;
    end;
    
  function find1(x,l,r,ll,rr,ct:longint):longint;
    var
      mid,res:longint;
      
    begin
      if (l>r)or(ll>rr)then begin find1:=0;exit;end;
      if (l=ll)and(r=rr)then begin
        if (ta[x][r]<=ct)then begin
          find1:=0;
          exit;
        end;
        while (l<r-1)do begin
          mid:=(l+r)shr 1;
          if (ta[x][mid]<=ct)
            then l:=mid
            else r:=mid;
        end;
        if (ta[x][l]>ct)then find1:=rr-l+1 else find1:=rr-r+1;
        exit;
      end;
      res:=0;
      mid:=(ll+rr)shr 1;
      if (l<=mid)then inc(res,find1(x+1,l,min(r,mid),ll,mid,ct));
      if (r>mid)then inc(res,find1(x+1,max(mid+1,l),r,mid+1,rr,ct));
      find1:=res;
    end;

  function find2(x,l,r,ll,rr,ct:longint):longint;
    var
      mid,res:longint;
      
    begin
      if (l>r)or(ll>rr)then begin find2:=0;exit;end;
      if (l=ll)and(r=rr)then begin
        if (ta[x][l]>=ct)then begin
          find2:=0;
          exit;
        end;
        while (l<r-1)do begin
          mid:=(l+r)shr 1;
          if (ta[x][mid]>=ct)
            then r:=mid
            else l:=mid;
        end;
        if (ta[x][r]<ct)then find2:=r-ll+1 else find2:=l-ll+1;
        exit;
      end;
      res:=0;
      mid:=(ll+rr)shr 1;
      if (l<=mid)then inc(res,find2(x+1,l,min(r,mid),ll,mid,ct));
      if (r>mid)then inc(res,find2(x+1,max(mid+1,l),r,mid+1,rr,ct));
      find2:=res;      
    end;


begin
  //assign(input,'input.txt');reset(input);
  //assign(output,'output.txt');rewrite(output);
  read(n,k);
  for i:=1 to n do read(a[i]);
  rec(1,1,n);
  inv:=0;
  for i:=1 to n do inv:=inv+find1(1,1,i-1,1,n,a[i]);
  r:=2;
  ans:=0;
  for l:=1 to n-1 do begin
    while (r<=n)and(inv>k)do begin
      ct:=find1(1,1,l,1,n,a[r])+find2(1,r+1,n,1,n,a[r]);
      inv:=inv-ct;
      inc(r);
    end;
    ans:=ans+n-r+1;
    if (r=l+1)then begin
      inc(r);
      continue;
    end;
    ct:=find1(1,1,l,1,n,a[l+1])+find2(1,r,n,1,n,a[l+1]);
    inv:=inv+ct;
  end;
  writeln(ans);
end.