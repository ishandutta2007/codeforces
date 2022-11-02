var
  l,r,ans,kf,kol,a:array[0..500500]of longint;
  n,m,i,j:longint;

begin
  read(n,m);
  for i:=1 to n do begin
    read(a[i]);
    if (a[i]>n)then continue;
    inc(kol[a[i]]);
  end;
  for i:=1 to m do begin
    read(l[i],r[i]);
    ans[i]:=0;
  end;
  for i:=1 to n do 
    if (kol[i]>=i)then begin
      kf[0]:=0;
      for j:=1 to n do 
        kf[j]:=kf[j-1]+ord(a[j]=i);
      for j:=1 to m do
        if (kf[r[j]]-kf[l[j]-1]=i)then inc(ans[j]);
    end;
  for i:=1 to m do writeln(ans[i]);
end.