uses math;
const
  inf=1000000000;
var
  t,x,u:array[0..555]of int64;
  o,n,i,j,k:longint;
  a,d:array[0..555,0..555]of longint;
begin
  read(n);
  for i:=1 to n do for j:=1 to n do begin
    read(a[i][j]);d[i][j]:=ord(i<>j)*inf;
  end;
  for i:=1 to n do read(x[i]);
  for o:=n downto 1 do begin
    i:=x[o];
    t[i]:=1;
    for j:=1 to n do begin
      d[i][j]:=min(d[i][j],a[i][j]);
      d[j][i]:=min(d[j][i],a[j][i]);
    end;
    for j:=1 to n do for k:=1 to n do begin
      d[j][k]:=min(d[j][k],d[j][i]+d[i][k]);
      inc(u[o],d[j][k]*t[j]*t[k]);
    end;
  end;
  for i:=1 to n do write(u[i],' ');
end.