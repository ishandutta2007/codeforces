var
  n,m,i,j:longint;
  a:array[1..1001,1..1111]of char;
  kx,ky:array[1..10000]of longint;
  res:int64;
begin
  fillchar(kx,sizeof(kx),$0);
  fillchar(ky,sizeof(ky),$0);
  readln(n,m);
  for i:=1 to n do begin
    for j:=1 to m do begin
      read(a[i][j]);
      if (a[i][j]='*')then begin
        inc(kx[i]);inc(ky[j]);
      end;
    end;
    readln;
  end;
  res:=0;
  for i:=1 to n do for j:=1 to m do
    if (a[i][j]='*')and(kx[i]>0)and(ky[j]>0)then
      inc(res,(kx[i]-1)*(ky[j]-1));
  writeln(res);
end.