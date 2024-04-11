const
  base=100000000;
var
  res,n1,n2,k1,k2,i,j,q1,q2:longint;
  f:array[0..111,0..111,0..11,0..11]of longint;

begin
  read(n1,n2,k1,k2);
  fillchar(f,sizeof(f),$0);
  f[0][0][0][0]:=1;
  for i:=0 to n1 do 
    for j:=0 to n2 do 
      for q1:=0 to k1 do 
        for q2:=0 to k2 do begin
          if (i+1<=n1)and(q1+1<=k1)then begin
            inc(f[i+1][j][q1+1][0],f[i][j][q1][q2]);
            if (f[i+1][j][q1+1][0]>=base)then dec(f[i+1][j][q1+1][0],base);
          end;
          if (j+1<=n2)and(q2+1<=k2)then begin
            inc(f[i][j+1][0][q2+1],f[i][j][q1][q2]);
            if (f[i][j+1][0][q2+1]>=base)then dec(f[i][j+1][0][q2+1],base);
          end;
        end;
  res:=0;
  for q1:=0 to k1 do 
    for q2:=0 to k2 do begin
      res:=res+f[n1][n2][q1][q2];
      if (res>=base)then dec(res,base);
    end;
  writeln(res);
end.