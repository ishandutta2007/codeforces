{$r-,q-,s-,i-,o+}
var
  j,tmp,hh,ka,kh,pr,i,l,r,n:longint;
  nq,nomh,x,w,t,nom,rx,ry,h:array[0..500500]of longint;
  procedure qs(l,r:longint);
    var
      i,j,xx:longint;
    begin
      i:=l;j:=r;
      xx:=x[(i+j)shr 1];
      while (i<=j)do begin
        while (xx>x[i])do inc(i);
        while (xx<x[j])do dec(j);
        if (i>j)then break;
        tmp:=x[i];x[i]:=x[j];x[j]:=tmp;
        tmp:=w[i];w[i]:=w[j];w[j]:=tmp;
        tmp:=t[i];t[i]:=t[j];t[j]:=tmp;
        tmp:=nom[i];nom[i]:=nom[j];nom[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<r)then qs(i,r);
      if (j>l)then qs(l,j);
    end;
  procedure swap(x,y:longint);
    begin
      tmp:=h[x];h[x]:=h[y];h[y]:=tmp;
      nomh[h[x]]:=x;
      nomh[h[y]]:=y;
    end;
  procedure down(q:longint);
    begin
      while (q>1)and(w[h[q]]>w[h[q shr 1]])do begin
        swap(q,q shr 1);
        q:=q shr 1;
      end;
    end;
  procedure up(q:longint);
    var
      y:longint;
    begin
      while (q+q<=kh)do begin
        y:=q+q;
        if (y+1<=kh)and(w[h[y+1]]>w[h[y]])then inc(y);
        if (w[h[q]]>=w[h[y]])then exit;
        swap(q,y);
        q:=y;
      end;
    end;
  procedure insert(q:longint);
    begin
      inc(kh);
      h[kh]:=q;
      nomh[q]:=kh;
      down(kh);   
    end;
  procedure erase(q:longint);
    begin
      swap(q,kh);
      dec(kh);
      up(q);
      down(q);
    end;
begin
  assign(input,'input.txt');reset(input);
  assign(output,'output.txt');rewrite(output);
  ka:=0;
  read(n);
  for i:=1 to n do begin
    read(hh,l,r);
    x[i]:=l;w[i]:=hh;t[i]:=-1;
    x[i+n]:=r;w[i+n]:=hh;t[i+n]:=1;
    nom[i]:=i;nom[i+n]:=i;
  end;
  x[n+n+1]:=-1000000001;w[n+n+1]:=0;t[n+n+1]:=-1;nom[n+n+1]:=n+1;
  x[n+n+2]:=1000000001;w[n+n+2]:=0;t[n+n+2]:=1;nom[n+n+2]:=n+1;
  qs(1,n+n+2);
//  for i:=1 to n+n+2 do writeln(x[i],' ',w[i],' ',t[i]);
  insert(1);
  x[n+n+3]:=maxlongint;
  for i:=2 to n+n+2 do begin
    if (x[i]<>x[i-1])then pr:=w[h[1]]; 
    if (t[i]<0)then begin
      insert(i);
      nq[nom[i]]:=i;
    end else erase(nomh[nq[nom[i]]]);
    if (w[h[1]]<>pr)and(x[i]<>x[i+1])then begin
      inc(ka);rx[ka]:=x[i];ry[ka]:=pr;
      inc(ka);rx[ka]:=x[i];ry[ka]:=w[h[1]];
    end;
  end;
  writeln(ka);
  for i:=1 to ka do writeln(rx[i],' ',ry[i]);
end.