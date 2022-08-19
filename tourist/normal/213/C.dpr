{$R-,S-,Q-,I-,O+}
const inf = round(1e9);
var
  n,i,j,s,si,sj,ft: longint;
  a,f,g: array [0..310,0..310] of longint;
begin
  read(n);
  for i:=1 to n do
    for j:=1 to n do read(a[i,j]);
  for i:=1 to n do
    for j:=1 to n do f[i,j]:=-inf;
  f[1,1]:=a[1,1];
  for s:=2 to n+n-1 do
  begin
    for i:=1 to n do
      for j:=1 to n do g[i,j]:=-inf;
    for i:=1 to n do
      for j:=1 to n do
        if f[i,j] > -9e8 then
          for si:=i to i+1 do
            for sj:=j to j+1 do
            begin
              if (si > n) or (sj > n) or (s+1-si > n) or (s+1-sj > n) then continue;
              ft:=f[i,j]+a[si,s+1-si];
              if si <> sj then inc(ft,a[sj,s+1-sj]);
              if ft > g[si,sj] then g[si,sj]:=ft;
            end;
    f:=g;
  end;
  writeln(f[n,n]);
end.