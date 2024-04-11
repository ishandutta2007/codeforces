var
  q,n,i,m,j,dl:longint;
  a,res,x,y:array[0..1111]of longint;
  was:array[0..1111]of boolean;
begin
  read(n,m);
  for i:=1 to n do read(x[i],y[i]);
  for i:=1 to m do read(a[i]);
  for i:=1 to m do was[i]:=false;
  for i:=1 to n do res[i]:=-1;
  i:=1;
  while (i<=n)do begin
    dl:=abs(x[i]-x[i+1])+abs(y[i]-y[i+1]);
    j:=i-1;
    if (j=0)then j:=n;
    dl:=dl+abs(x[i]-x[j])+abs(y[i]-y[j]);
    for q:=1 to m do 
      if (not was[q])and(dl=a[q])then begin
        was[q]:=true;
        res[i]:=q;
        break;
      end;
    if (res[i]<0)then break;
    inc(i,2);
  end;
  if (res[i]<0)then begin
    for i:=1 to m do was[i]:=false;
    for i:=1 to n do res[i]:=-1;
    i:=2;
    while (i<=n)do begin
      j:=i+1;
      if (j>n)then dec(j,n);
      dl:=abs(x[i]-x[j])+abs(y[i]-y[j]);
      j:=i-1;
      if (j=0)then j:=n;
      dl:=dl+abs(x[i]-x[j])+abs(y[i]-y[j]);
      for q:=1 to m do 
        if (not was[q])and(dl=a[q])then begin
          was[q]:=true;
          res[i]:=q;
          break;
        end;
      if (res[i]<0)then break;
      inc(i,2);
    end;
    if (res[i]<0)then begin
      writeln('NO');
      exit;
    end;
  end;
  writeln('YES');
  for i:=1 to n do write(res[i],' ');
  writeln;
end.