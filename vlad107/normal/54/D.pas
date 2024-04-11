var
  nnn,q,nj,x,n,k,m,i,j:longint;
  g,f:array[0..555,0..555]of longint;
  s:string;
  ch:char;
  z,mo,a,b:array[0..555]of longint;
begin
  readln(n,k);
  nnn:=n;
  readln(s);
  m:=length(s);
  for i:=1 to m do b[i]:=ord(s[i])-96;
  for i:=1 to n-m+1 do begin
    read(ch);
    mo[i]:=ord(ch)-48;
  end;
  fillchar(f,sizeof(f),$FF);
  z[1]:=0;
  j:=0;
  for i:=2 to m do begin
    while (j>0)and(b[i]<>b[j+1])do j:=z[j];
    if (b[i]=b[j+1])then inc(j);
    z[i]:=j;
  end;
  f[0][0]:=0;
  for i:=1 to n do
    for j:=0 to m do if (f[i-1][j]>-1)then
      for q:=1 to k do begin
        nj:=j;
        while (nj>0)and(q<>b[nj+1])do nj:=z[nj];
        if (q=b[nj+1])then inc(nj);
        if (nj=m)and(mo[i-m+1]=0)then continue;
        if (i>=m)and(mo[i-m+1]=1)and(nj<>m)then continue;
        f[i][nj]:=j;
        g[i][nj]:=q;
      end;
  if (mo[n-m+1]=1)then begin
    if (f[n][m]=-1)then begin
      writeln('No solution');
      exit;
    end;
    x:=m;
  end else begin
    x:=-1;
    for j:=0 to m-1 do
      if (f[n][j]<>-1)then begin
        x:=j;
      end;
    if (x<0)then begin
      writeln('No solution');
      exit;
    end;
  end;
  while (n>0)do begin
    a[n]:=g[n][x];
    x:=f[n][x];
    dec(n);
  end;
  for i:=1 to nnn do
    write(chr(a[i]+96));
  writeln;
end.