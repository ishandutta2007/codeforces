{$r-,q-,s-,i-,o+}
var
  res,l1,l2,n,m,i,j:longint;
  kol,d,a,b:array[0..100500]of longint;
  procedure update(x,k:longint);
    begin
      if (d[x]=-1)or(k<d[x])then begin
        kol[x]:=1;
        d[x]:=k;
        exit;
      end;
      if (k=d[x])then inc(kol[x]);
    end;
begin
  //assign(input,'input.txt');reset(input);
  //assign(output,'output.txt');rewrite(output);
  read(m,n,i,j);
  for i:=1 to m do read(b[i]);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do kol[i]:=0;
  for i:=1 to n do d[i]:=-1;
  j:=1;
  for i:=1 to m do begin
    while (j<n)and(b[i]>=a[j+1])do inc(j);
    if (b[i]<a[j])then begin
      kol[j]:=1;
      if (d[j]=-1)or(abs(a[j]-b[i])<d[j])then d[j]:=abs(a[j]-b[i]);
      continue;
    end;
    if (j=n)then begin
      update(j,abs(a[j]-b[i]));
      continue;
    end;
    l1:=abs(a[j]-b[i]);
    l2:=abs(a[j+1]-b[i]);
    if (l1<l2)then update(j,abs(a[j]-b[i]))else
    if (l1>l2)then update(j+1,abs(a[j+1]-b[i]))else 
    if (d[j]=-1)or(d[j]=abs(a[j]-b[i]))then begin
      inc(kol[j]);
      d[j]:=abs(a[j]-b[i]);
    end else update(j+1,abs(a[j+1]-b[i]));
  end;
  res:=0;
  for i:=1 to n do inc(res,kol[i]);
  writeln(m-res);
  close(output);close(input);
end.