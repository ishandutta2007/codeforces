{$r-,q-,s-,i-,o+}
const
  inf:int64=1000000000000000000;
var
  sum,t1,t2:array[0..500500]of int64;
  b,nom,a,next,n1,n2:array[0..500500]of longint;
  f:array[0..1111,0..1111]of int64;
  pr:array[0..1111,0..1111]of longint;
  x,n,k,i,j:longint;
  cr:int64;
  
  procedure qs(l,r:longint);
    var
      nn,i,j,tmp,xx:longint;
      
    begin
      i:=l;j:=r;
      nn:=l+random(r-l+1);
      xx:=a[nn];
      while (i<=j)do begin
        while (xx>a[i])do inc(i);
        while (xx<a[j])do dec(j);
        if (i>j)then break;
        tmp:=a[i];a[i]:=a[j];a[j]:=tmp;
        tmp:=b[i];b[i]:=b[j];b[j]:=tmp;
        tmp:=nom[i];nom[i]:=nom[j];nom[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<r)then qs(i,r);
      if (j>l)then qs(l,j);
    end;
  

begin
  //assign(input,'input.txt');reset(input);
  //assign(output,'output.txt');rewrite(output);
  read(n,k);
  for i:=1 to n do begin
    read(a[i],b[i]);
    a[i]:=a[i]+a[i];
  end;
  for i:=1 to n do nom[i]:=i;
  qs(1,n);
  for i:=1 to n do begin
    j:=i;
    while (j<=n)and(b[j]=2)do inc(j);
    next[i]:=j;
  end;
  sum[0]:=0;
  for i:=1 to n do sum[i]:=sum[i-1]+a[i];
  for i:=0 to k do 
    for j:=0 to n do f[i][j]:=inf;
  f[0][0]:=0;
  for i:=1 to k do begin
    for j:=0 to n do t1[j]:=inf;
    for j:=1 to n do begin
      if (j>0)and(t1[j-1]+a[j]<t1[j])then begin
        t1[j]:=t1[j-1]+a[j];
        n1[j]:=n1[j-1];
      end;
      if (f[i-1][j-1]<>inf)and(f[i-1][j-1]+a[j]<t1[j])then begin
        t1[j]:=f[i-1][j-1]+a[j];
        n1[j]:=j-1;
      end;
    end;
    for j:=0 to n do t2[j]:=inf;
    for j:=0 to n do begin
      if (j>0)and(t2[j-1]+a[j]<t2[j])then begin
        t2[j]:=t2[j-1]+a[j];
        n2[j]:=n2[j-1];
      end;
      if (next[j+1]<>n+1)and(next[j+1]<>0)then begin
        x:=next[j+1];
        cr:=f[i-1][j]+a[j+1]div 2+sum[x]-sum[j+1];
        if (cr<t2[x])then begin
          t2[x]:=cr;
          n2[x]:=j;
        end;
      end;
    end;    
    for j:=0 to n do begin
      if (t1[j]<t2[j])then begin
        f[i][j]:=t1[j];
        pr[i][j]:=n1[j];
      end else begin
        f[i][j]:=t2[j];
        pr[i][j]:=n2[j];
      end;
      if (f[i][j]>=inf)then begin
        f[i][j]:=inf;
        pr[i][j]:=0;
      end;
    end;
  end;
  writeln((f[k][n]/2):0:1);
  x:=n;
  for i:=k downto 1 do begin
    write(x-pr[i][x]);
    for j:=pr[i][x]+1 to x do write(' ',nom[j]);
    writeln;
    x:=pr[i][x];
  end;
  //close(output);close(input);
end.