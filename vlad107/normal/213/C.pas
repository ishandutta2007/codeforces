{$r-,q-,s-,i-,o+}
const
  inf=1000000000;

var
  f:array[0..1,0..333,0..333]of longint;
  a:array[0..333,0..333]of longint;
  sum,t1,t2,q,n,i,j,x1,y1,x2,y2,cr:longint;

begin
  read(n);
  for i:=1 to n do for j:=1 to n do read(a[i][j]);
  for i:=1 to n do for j:=1 to n do f[0][i][j]:=-inf;
  f[0][1][1]:=a[1][1];q:=0;
  for sum:=2 to 2*n-1 do begin
    for i:=1 to n do for j:=1 to n do f[1-q][i][j]:=-inf;
    for i:=1 to n do 
      for j:=1 to n do 
        if (f[q][i][j]<>-inf)then 
          for t1:=0 to 1 do 
            for t2:=0 to 1 do 
              if (i+t1<=n)and(j+t2<=n)then begin
                x1:=i+t1;x2:=j+t2;
                y1:=sum+1-x1;
                y2:=sum+1-x2;
                if (y1<1)or(y1>n)or(y2<1)or(y2>n)then continue;
                if (x1<1)or(x1>n)or(x2<1)or(x2>n)then continue;
                cr:=f[q][i][j]+a[x1][y1];
                if (x2<>x1)or(y2<>y1)then cr:=cr+a[x2][y2];
                if (cr>f[1-q][i+t1][j+t2])then f[1-q][i+t1][j+t2]:=cr;
              end;
    q:=1-q;
  end;
  writeln(f[q][n][n]);
end.