var
  ans,i,j,k,n:longint;
  t,w:array[0..500500]of longint;
  f:array[0..101,0..202,0..202]of boolean;

begin
  read(n);
  for i:=1 to n do read(t[i],w[i]);
  f[0][0][0]:=true;
  for i:=0 to n-1 do 
    for j:=0 to 2*n do 
      for k:=0 to 2*n do 
        if (f[i][j][k])then begin
          f[i+1][j+t[i+1]][k]:=true;
          if (k+w[i+1]<=2*n)then f[i+1][j][k+w[i+1]]:=true;
        end;
  ans:=2*n;
  for j:=0 to 2*n do 
    for k:=0 to j do 
      if (f[n][j][k])and(j<ans)then ans:=j;
  writeln(ans);
end.