{$r-,q-,s-,i-,o+}
var
  j,x,n,m,i,t,sq:longint;
  cr:int64;
  f,res:array[0..500500]of int64;
  et,b,nom,a:array[0..500500]of longint;
  procedure qs(l,r:longint);
    var
      i,j,x,tmp:longint;
    begin
      i:=l;j:=r;
      x:=b[l+random(r-l+1)];
      while (i<=j)do begin
        while (x>b[i])do inc(i);
        while (x<b[j])do dec(j);
        if (i>j)then break;
        tmp:=b[i];b[i]:=b[j];b[j]:=tmp;
        tmp:=a[i];a[i]:=a[j];a[j]:=tmp;
        tmp:=nom[i];nom[i]:=nom[j];nom[j]:=tmp;
        inc(i);dec(j);
      end;
      if (i<r)then qs(i,r);
      if (j>l)then qs(l,j);
    end;

begin
//  assign(input,'input.txt');reset(input);
//  assign(output,'output.txt');rewrite(output);
  read(n);
  for i:=1 to n do read(et[i]);
  read(m);
  for i:=1 to m do begin
    read(a[i],b[i]);
    nom[i]:=i;
  end;
  qs(1,m);
  i:=1;
  sq:=trunc(sqrt(n));
  while (i<=m)do begin
    if (b[i]>sq)then begin
      x:=a[i];
      cr:=0;
      while (x<=n)do begin
        cr:=cr+et[x];
        inc(x,b[i]);
      end;
      res[nom[i]]:=cr;
      inc(i);
      continue;
    end;
    t:=b[i];
    for j:=n downto 1 do 
      if (j+t>n)then f[j]:=et[j] else f[j]:=f[j+t]+et[j];
    while (i<=m)and(b[i]=t)do begin
      res[nom[i]]:=f[a[i]];
      inc(i);
    end;
  end;
  for i:=1 to m do writeln(res[i]);
  close(output);
end.