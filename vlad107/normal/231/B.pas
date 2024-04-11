var
  ans:array[0..500500]of longint;
  f:array[0..111,-11111..11111]of longint;
  tk,d,n,x,i,j,k,l:longint;

begin
  read(n,d,l);
  fillchar(F,sizeof(f),$0);
  f[0][0]:=-1;
  for i:=0 to n-1 do 
    for j:=-l*n to n*l do 
      if (f[i][j]<>0)then 
        for k:=1 to l do begin
          tk:=k;
          if (i and 1=1)then tk:=-tk;
          if (j+tk>=-l*n)and(j+tk<=n*l)and(f[i+1][j+tk]=0)then f[i+1][j+tk]:=tk;
        end;
  if (f[n][d]=0)then begin
    writeln(-1);
    exit;
  end;
  for i:=n downto 1 do begin
    ans[i]:=abs(f[i][d]);
    d:=d-f[i][d];
  end;
  for i:=1 to n do write(ans[i],' ');
  writeln;
end.