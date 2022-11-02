{$r-,q-,s-,i-,o+}
var
  j,a1,a2,x,y,lst,n,i,m,kh:longint;
  pred,last,kolf,revn,h,p,c,nom,nc:array[0..300500]of longint;
  cntf:array[0..300500]of int64;
  ans:int64;

  procedure qs1(l,r:longint);
    var
      nn,i,j,xx,tmp:longint;
      
    begin
      i:=l;j:=r;
      nn:=l+random(r-l+1);
      xx:=p[nn];
      while (i<=j)do begin
        while (xx<p[i])do inc(i);
        while (xx>p[j])do dec(j);
        if (i>j)then break;
        tmp:=p[i];p[i]:=p[j];p[j]:=tmp;
        tmp:=c[i];c[i]:=c[j];c[j]:=tmp;
        tmp:=nom[i];nom[i]:=nom[j];nom[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<r)then qs1(i,r);
      if (j>l)then qs1(l,j);
    end;
    
  procedure qs3(l,r:longint);
    var
      nn,i,j,xx,tmp:longint;
      
    begin
      i:=l;j:=r;
      nn:=l+random(r-l+1);
      xx:=c[nn];
      while (i<=j)do begin
        while (xx>c[i])do inc(i);
        while (xx<c[j])do dec(j);
        if (i>j)then break;
        tmp:=p[i];p[i]:=p[j];p[j]:=tmp;
        tmp:=c[i];c[i]:=c[j];c[j]:=tmp;
        tmp:=nom[i];nom[i]:=nom[j];nom[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<r)then qs3(i,r);
      if (j>l)then qs3(l,j);
    end;
    
  procedure qs2(l,r:longint);
    var
      i,j,nn,xx,tmp:longint;
      
    begin
      i:=l;j:=r;
      nn:=l+random(r-l+1);
      xx:=nc[nn];
      while (i<=j)do begin
        while (kolf[last[xx]]<kolf[last[nc[i]]])do inc(i);
        while (kolf[last[xx]]>kolf[last[nc[j]]])do dec(j);
        if (i>j)then break;
        tmp:=nc[i];nc[i]:=nc[j];nc[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<r)then qs2(i,r);
      if (j>l)then qs2(l,j);
    end;
    
  procedure swap(x,y:longint);
    var
      tmp:longint;
      
    begin
      tmp:=h[x];h[x]:=h[y];h[y]:=tmp;
      revn[h[x]]:=x;
      revn[h[y]]:=y;
    end;
    
  procedure up(x:longint);
    begin
      while (x+x<=kh)do begin 
        y:=x+x;
        if (y<kh)and(cntf[last[h[y+1]]]>cntf[last[h[y]]])then inc(y);
        if (cntf[last[h[x]]]>=cntf[last[h[y]]])then break;
        swap(x,y);
        x:=y;
      end;
    end;
    
  procedure down(x:longint);
    begin
      while (x>1)and(cntf[last[h[x]]]>cntf[last[h[x shr 1]]])do begin
        swap(x,x shr 1);
        x:=x shr 1;
      end;
    end;

begin
  //assign(input,'input.txt');reset(input);
  randomize;
  ans:=0;
  read(n);
  for i:=1 to n do read(c[i],p[i]);
  for i:=1 to n do nom[i]:=i;
  qs3(1,n);
  c[0]:=0;
  lst:=0;
  for i:=1 to n do 
    if (c[i]=lst)
      then c[i]:=c[i-1]
      else begin
        lst:=c[i];
        c[i]:=c[i-1]+1;
      end;
  m:=c[n];
  qs1(1,n);
  for i:=1 to n do begin
    pred[i]:=last[c[i]];
    kolf[i]:=kolf[pred[i]]+1;
    cntf[i]:=cntf[pred[i]]+p[i];
    last[c[i]]:=i;
  end;
  for i:=1 to m do nc[i]:=i;
  qs2(1,m);
  kh:=0;
  for i:=1 to m do begin
    x:=nc[i];
    for j:=1 to i-1 do begin
      y:=nc[j];
      if (kolf[last[y]]<=kolf[last[x]]+1)then break;
      while (kolf[last[y]]>kolf[last[x]]+1)do last[y]:=pred[last[y]];
      up(revn[y]);
    end;
    if (kh>0)then begin
      y:=h[1];
      if (cntf[last[y]]+cntf[last[x]]>ans)then begin
        a1:=last[y];
        a2:=last[x];
        ans:=cntf[a1]+cntf[a2];
      end;
    end;
    inc(kh);
    h[kh]:=x;
    revn[x]:=kh;
    down(kh);
  end;
  writeln(ans);
  writeln(kolf[a1]+kolf[a2]);
  if (kolf[a1]<kolf[a2])then begin
    i:=a1;a1:=a2;a2:=i;
  end;
  while (a1>0)do begin
    write(nom[a1],' ');
    if (a2>0)then write(nom[a2],' ');
    a1:=pred[a1];
    a2:=pred[a2];
  end;
  writeln;
end.