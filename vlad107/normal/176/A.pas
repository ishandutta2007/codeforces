uses
  math;

var
  t,u,f:array[0..555]of longint;
  ans,i,j,q,m,n,k:longint;
  s:ansistring;
  a,b,c:array[0..555,0..555]of longint;

  procedure solve;
    var
      i,j,o:longint;

    begin
      for i:=0 to k do f[i]:=-1;
      f[0]:=0;
      for i:=1 to m do
        for o:=k downto 0 do
          if (f[o]<>-1)then
            for j:=0 to u[i] do
              if (o+j<=k)
                then f[o+j]:=max(f[o+j],f[o]+j*t[i])
                else break;
      for i:=0 to k do
        ans:=max(ans,f[i]);
    end;

begin
  readln(n,m,k);
  for i:=1 to n do begin
    readln(s);
    for j:=1 to m do read(a[i][j],b[i][j],c[i][j]);
    readln;
  end;
  ans:=0;
  for i:=1 to n do
    for j:=1 to n do
      if (i<>j)then begin
        for q:=1 to m do t[q]:=b[j][q]-a[i][q];
        for q:=1 to m do u[q]:=c[i][q];
        solve;
      end;
  writeln(ans);
end.