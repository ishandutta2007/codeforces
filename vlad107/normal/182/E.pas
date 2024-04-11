const
  base=1000000007;

var
  m,x,y,res,n,l,i,j,k:longint;
  nom,a,b:array[0..500]of longint;
  f:array[0..3333,0..422]of longint;

begin
  read(m,l);
  n:=0;
  for i:=1 to m do begin
    inc(n);nom[n]:=i;
    read(a[n],b[n]);
    x:=a[n];y:=b[n];
    if (x=y)then continue;
    inc(n);nom[n]:=i;
    a[n]:=y;b[n]:=x;
  end;
  fillchar(f,sizeof(f),$0);
  f[0][0]:=1;
  for i:=0 to l-1 do   
    for j:=0 to n do
      if (f[i][j]<>0)then begin
        for k:=1 to n do 
          if (nom[j]<>nom[k])and((i=0)or(a[k]=b[j]))then begin
            inc(f[i+a[k]][k],f[i][j]);
            if (f[i+a[k]][k]>=base)then dec(f[i+a[k]][k],base);
          end;
      end;
  res:=0;
  for i:=0 to n do begin
    inc(res,f[l][i]);     
    if (res>=base)then dec(res,base);
  end;
  writeln(res);     
end.