{$r-,q-,s-,i-,o+}
var
  res,cr:extended;
  x,p,s,ut,n,i,j,m:longint;
  a,b:array[0..500500]of longint;
  f:array[0..55,0..55,0..55]of int64;

begin
  read(n);
  s:=0;
  for i:=1 to n do begin
    read(a[i]);
    s:=s+a[i];
  end;
  read(p);
  if (s<=p)then begin
    writeln(n);
    exit;
  end;
  for i:=1 to n do b[i]:=a[i];
  m:=n;
  dec(n);
  res:=0;
  
  for x:=1 to m do begin
    j:=0;
    for i:=1 to m do 
      if (i<>x)then begin
        inc(j);
        a[j]:=b[i];
      end;
    for i:=0 to n do 
      for j:=0 to n do 
        for s:=0 to p do f[i][j][s]:=0;
    f[0][0][0]:=1;
    for i:=0 to n-1 do 
      for j:=0 to i do 
        for s:=0 to p do begin
          f[i+1][j][s]:=f[i+1][j][s]+f[i][j][s];
          if (s+a[i+1]<=p)
            then f[i+1][j+1][s+a[i+1]]:=f[i+1][j+1][s+a[i+1]]+f[i][j][s];
        end;
    for i:=0 to n do
      for s:=0 to p do 
        if (s+b[x]>p)and(f[n][i][s]<>0)then begin
          cr:=f[n][i][s];
          for ut:=i+1 to m do cr:=cr/ut;
          for ut:=1 to m-i-1 do cr:=cr*ut;
          res:=res+cr*i;
        end;
  end;
  writeln(res:0:10);
end.