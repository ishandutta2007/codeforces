var
  sx,sy,tk,ans,n,m,i,j,cr,k:longint;
  sum,a:array[0..555,0..555]of longint;
  
  function fsum(x1,y1,x2,y2:longint):longint;inline;
    begin
      fsum:=sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
    end;

begin
  read(n,m);
  for i:=1 to n do for j:=1 to m do read(a[i][j]);
  fillchar(sum,sizeof(sum),$0);
  ans:=-1000000000;
  for i:=1 to n do 
    for j:=1 to m do 
      sum[i][j]:=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
  for i:=1 to n-2 do 
    for j:=1 to m-2 do begin
      cr:=fsum(i,j,i+2,j+2)-a[i+1][j]-a[i+1][j+1];
      k:=3;
      sx:=i;sy:=j;
      for tk:=1 to 500 do begin
        if (sx+k-1>n)or(sy+k-1>m)then break;
        if (cr>ans)then ans:=cr;
        inc(k,2);
        dec(sx);
        dec(sy);
        if (sx<1)or(sy<1)then break;
        cr:=fsum(sx,sy,sx+k-1,sy+k-1)-cr-a[sx+1][sy];
      end;
    end;
  writeln(ans);
end.