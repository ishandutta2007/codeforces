{$r-,q-,s-,i-,o+}
var
  last,tmp,x,j,kr,n,kq,i:longint;
  r1,r2,t,q,a,b,nom,rev:array[0..500500]of longint;
  nice,was:Array[0..500500]of boolean;
  procedure qs(l,r:longint);
    var
      xx,i,j,tmp:longint;
    begin
      i:=l;j:=r;
      xx:=b[i+random(r-l+1)];
      while (i<=j)do begin
        while (xx>b[i])do inc(i);
        while (xx<b[j])do dec(j);
        if (i>j)then break;
        tmp:=b[i];b[i]:=b[j];b[j]:=tmp;
        tmp:=nom[i];nom[i]:=nom[j];nom[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<r)then qs(i,r);
      if (j>l)then qs(l,j);
    end;
  procedure swap(x,y:longint);
    begin
      if (x=0)or(y=0)or(x=y)then exit;
      inc(kr);
      r1[kr]:=x;
      r2[kr]:=y;
      tmp:=a[x];a[x]:=a[y];a[y]:=tmp;
      rev[a[x]]:=x;
      rev[a[y]]:=y;
    end;
begin 
  randomize;
  //assign(input,'input.txt');reset(input);
  //assign(output,'output.txt');rewrite(output);
  read(n);
  for i:=1 to n do begin
    read(a[i]);
    b[i]:=a[i];
    nom[i]:=i;
  end;
  qs(1,n);
  b[0]:=0;
  last:=0;
  for i:=1 to n do begin
    last:=b[i];
    b[i]:=b[i-1]+1;
    t[b[i]]:=last;
    x:=last;
    while (x>0)do begin
      if (x mod 10<>4)and(x mod 10<>7)then break;
      x:=x div 10;
    end;
    if (x=0)then nice[b[i]]:=true else nice[b[i]]:=false;
    a[nom[i]]:=b[i];
  end;
  kq:=0;
  for i:=1 to n do 
    if (nice[i])then begin
      inc(kq);
      q[kq]:=i; 
    end;
  for i:=1 to n do rev[a[i]]:=i;
  fillchar(was,sizeof(was),$0);
  kr:=0;
  i:=1;
  j:=1;
  while (i<=n)and(j<=kq)do begin
    if (a[i]=b[i])then begin
      was[a[i]]:=true;
      inc(i);
      continue;
    end;
    if (nice[a[i]])then begin
      swap(i,rev[b[i]]);
      continue;
    end;
    while (j<=kq)and(was[q[j]])do inc(j);
    if (j>kq)then break;
    swap(i,rev[q[j]]);
  end;
  while (i<=n)and(t[a[i]]=t[b[i]])do inc(i);
  if (i<=n)and(kq=0)then begin
    writeln(-1);
    exit
  end;
  j:=rev[q[1]];
  while (i<=n)do begin
    if (a[i]=b[i])then begin
      inc(i);
      continue;
    end;
    swap(i,rev[q[1]]);
    swap(i,rev[b[i]]);
  end;
  swap(j,rev[q[1]]);
  if (i<=n)then begin
    writeln(-1);
    exit;
  end;
  writeln(kr);
  for i:=1 to kr do writeln(r1[i],' ',r2[i]);
  close(output);close(input);
end.