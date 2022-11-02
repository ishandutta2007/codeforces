{$r-,q-,s-,i-,o+}
var
  res:int64;
  mt,x,n,m,i,j,last:longint;
  nh,h,revh,a,c,nom:array[0..500500]of longint;
  
  procedure swap(x,y:longint);
    var
      tmp:longint;
    
    begin
      tmp:=h[x];h[x]:=h[y];h[y]:=tmp;
      tmp:=nh[x];nh[x]:=nh[y];nh[y]:=tmp;
      revh[nh[x]]:=x;revh[nh[y]]:=y;    
    end;
  
  procedure up(x:longint);
    var
      y:longint;
      
    begin
      while (x+x<=n)do begin
        y:=x+x;
        if (y<n)and(h[y+1]>h[y])then inc(y);
        if (h[x]>=h[y])then break;
        swap(x,y);
        x:=y;
      end;
    end;
    
  procedure down(x:longint);
    begin
      while (x>1)and(h[x]>h[x shr 1])do begin
        swap(x,x shr 1);
        x:=x shr 1;
      end;
    end;
  
  procedure qs(l,r:longint);
    var
      i,j,xx,tmp:longint;
      
    begin
      i:=l;j:=r;
      xx:=c[l+random(r-l+1)];
      while (i<=j)do begin
        while (xx>c[i])do inc(i);
        while (xx<c[j])do dec(j);
        if (i>j)then break;
        tmp:=c[i];c[i]:=c[j];c[j]:=tmp;
        tmp:=nom[i];nom[i]:=nom[j];nom[j]:=tmp;
        inc(I);dec(j);
      end;
      if (I<r)then qs(i,r);
      if (j>l)then qs(l,j);
    end;

begin
  //assign(input,'input.txt');reset(input);
  read(n,m);
  for i:=1 to n do begin
    read(c[i]);
    nom[i]:=i;
  end;
  qs(1,n);
  c[0]:=0;
  last:=0;
  for i:=1 to n do 
    if (c[i]=last)
      then c[i]:=c[i-1]
      else begin
        last:=c[i];
        c[i]:=c[i-1]+1;
      end;
  for i:=1 to n do a[nom[i]]:=c[i];
  mt:=c[n];
  for i:=1 to mt do begin
    h[i]:=0;
    revh[i]:=i;
    nh[i]:=i;
  end;
  j:=0;
  res:=0;
  for i:=1 to n do begin
    if (i>1)then begin
      x:=a[i-1];
      dec(h[revh[x]]);
      up(revh[x]);
    end;
    if (j<i)then j:=i-1;
    while (j<n)and(h[1]<m)do begin
      inc(j);
      x:=a[j];
      inc(h[revh[x]]);
      down(revh[x]);
    end;
    if (h[1]>=m)then res:=res+n-j+1;
  end;
  writeln(res);
end.