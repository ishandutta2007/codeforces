{$r-,q-,s-,i-,o+}
var
  maxx,minx,px,t,a,nom,left,right,rnom,ll,nl:array[0..200500]of longint;
  k1,k2:array[0..200500]of int64;
  kleaf,k,lx,rx,x,i,n,root:longint;
  procedure predfs(x:longint);
    begin
      if (left[x]<0)then begin
        minx[x]:=t[x];
        maxx[x]:=t[x];
        exit;
      end;
      predfs(left[x]);
      predfs(right[x]);
      minx[x]:=minx[left[x]];
      maxx[x]:=maxx[right[x]];
    end;
  procedure dfs(x:longint;q1,q2:int64);
    begin
      if (left[x]<0)then begin
        k1[rnom[x]]:=q1;
        k2[rnom[x]]:=q2;
        exit;
      end;
      dfs(left[x],q1+minx[right[x]],q2+1);
      dfs(right[x],q1+maxx[left[x]],q2+1);
    end;
  procedure qs(l,r:longint);
    var
      i,j,tmp,xx:longint;
    begin
      xx:=a[l+random(r-l+1)];
      i:=l;j:=r;
      while (i<=j)do begin
        while (xx>a[i])do inc(i);
        while (xx<a[j])do dec(j);
        if (i>j)then break;
        tmp:=a[i];a[i]:=a[j];a[j]:=tmp;
        tmp:=nom[i];nom[i]:=nom[j];nom[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<r)then qs(i,r);
      if (j>l)then qs(l,j);
    end;
begin
  randomize;
  read(n);
  for i:=1 to n do read(px[i],t[i]);
  fillchar(left,sizeof(left),$FF);
  fillchar(right,sizeof(right),$FF);
  for i:=1 to n do begin
    if (px[i]<0)then begin
      root:=i;
      continue;
    end;
    if (t[i]>t[px[i]])
      then right[px[i]]:=i
      else left[px[i]]:=i;
  end;
  for i:=1 to n do a[i]:=t[i];
  for i:=1 to n do nom[i]:=i;
  qs(1,n);
  for i:=1 to n do rnom[nom[i]]:=i;
  kleaf:=0;
  for i:=1 to n do 
    if (left[i]<0)then begin
      inc(kleaf);
      x:=rnom[i];
      nl[kleaf]:=i;
      if (x=1)then ll[kleaf]:=0 else ll[kleaf]:=a[x-1];
    end;
  for i:=1 to kleaf do begin
    a[i]:=ll[i];
    nom[i]:=nl[i];
  end;
  qs(1,kleaf);
  for i:=1 to kleaf do rnom[nom[i]]:=i;
  predfs(root);
  dfs(root,0,0);
  read(k);
//  for i:=1 to kleaf do writeln(a[i],' ',k1[i],' ',k2[i],' !!!');
  for i:=1 to k do begin
    read(x);
    lx:=1;rx:=kleaf;
    while (rx-lx>1)do 
      if (x>a[(lx+rx)shr 1])
        then lx:=(lx+rx)shr 1
        else rx:=(lx+rx)shr 1;
    if (x>a[rx])then lx:=rx;
//    writeln(lx);
    writeln(k1[lx]/k2[lx]:0:10);
  end;
end.