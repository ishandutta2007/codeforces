{$r-,q-,s-,i-,o+}
{$M 10000000}
uses
  math;

var
  tmp,tt,l1,r1,l2,r2,n,i,x,a,b,c,d:longint;
  u,v,rv:array[0..1500500]of longint;
  e:array[0..21,0..1500000]of longint;
  
  procedure build(x,l,r:longint);
    var
      mid,j1,j2,i:longint;
    begin
      if (l=r)then begin
        e[x][l]:=u[l];
        exit;
      end;
      mid:=(l+r)shr 1;
      build(x+1,l,mid);
      build(x+1,mid+1,r);
      j1:=l;j2:=mid+1;
      for i:=l to r do 
        if (j2>r)or((j1<=mid)and(j2<=r)and(e[x+1][j1]<e[x+1][j2]))then begin
          e[x][i]:=e[x+1][j1];
          inc(j1);
        end else begin
          e[x][i]:=e[x+1][j2];
          inc(j2);
        end;
    end;
    
  function solve(x,tl,tr,l1,r1,l2,r2:longint):longint;
    var
      ll,rr,mid,res:longint;
    begin
      if (l1=tl)and(r1=tr)then begin
        ll:=tl-1;rr:=tr+1;
        while (ll<rr-1)do 
          if (e[x][(ll+rr)shr 1]<=r2)
            then ll:=(ll+rr)shr 1
            else rr:=(ll+rr)shr 1;
        res:=ll-(tl-1);
        ll:=tl-1;rr:=tr+1;
        while (ll<rr-1)do 
          if (e[x][(ll+rr)shr 1]<l2)
            then ll:=(ll+rr)shr 1
            else rr:=(ll+rr)shr 1;
        solve:=res-(ll-(tl-1));
        exit;
      end;
      res:=0;
      mid:=(tl+tr)shr 1;
      if (l1<=mid)then inc(res,solve(x+1,tl,mid,l1,min(r1,mid),l2,r2));
      if (r1>mid)then inc(res,solve(x+1,mid+1,tr,max(l1,mid+1),r1,l2,r2));
      solve:=res;
    end;

begin
  read(n);
  for i:=1 to n do read(u[i]);
  for i:=1 to n do read(v[i]);
  for i:=1 to n do rv[v[i]]:=i;
  for i:=1 to n do u[i]:=rv[u[i]];
  build(1,1,n);
  read(tt);
  x:=0;
  while (tt>0)do begin
    dec(tt);
    read(a,b,c,d);
    l1:=(a+x-1)mod n+1;r1:=(b+x-1)mod n+1;
    if (l1>r1)then begin tmp:=l1;l1:=r1;r1:=tmp; end;
    l2:=(c+x-1)mod n+1;r2:=(d+x-1)mod n+1;
    if (l2>r2)then begin tmp:=l2;l2:=r2;r2:=tmp; end;
    x:=solve(1,1,n,l1,r1,l2,r2)+1;
    writeln(x-1);
  end;
end.