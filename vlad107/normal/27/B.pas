var
  k,n,m,i,j,x,y:longint;
  a:array[1..1000,1..1000]of longint;
begin
  read(n);
  m:=n*(n-1)shr 1;
  fillchar(a,sizeof(a),$0);
  for i:=1 to m-1 do begin
    read(x,y);
    a[x][y]:=1;
    a[y][x]:=2;
  end;
  for i:=1 to n do
    for j:=i+1 to n do
      if (a[i][j]=0)then begin
        for k:=1 to n do
          if (a[i][k]<>0)and(a[i][k]=a[k][j])then begin
            a[i][j]:=a[i][k];
            break;
          end;
        if (a[i][j]=1)
          then writeln(i,' ',j)
          else writeln(j,' ',i);
        exit;
      end;
end.