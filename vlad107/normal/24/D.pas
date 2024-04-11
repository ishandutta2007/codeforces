var
  i,j,k,n,m,x,y:longint;
  tu:extended;
  q,f:array[0..1111,0..1111]of extended;

begin
  read(n,m,x,y);
  if (m=1)then begin writeln(2*(n-x));exit;end;
  for i:=1 to m do f[n][i]:=0;
  for i:=n-1 downto x do begin
    for j:=2 to m-1 do begin q[j][2]:=3;q[j][3]:=-1;q[j][4]:=f[i+1][j]+4; end;
    q[1][2]:=2;q[1][3]:=-1;q[1][4]:=f[i+1][1]+3;
    q[m][2]:=2;q[m][3]:=0;q[m][4]:=f[i+1][m]+3;
    for j:=2 to m do begin
      q[j][2]:=q[j][2]+q[j-1][3]/q[j-1][2];
      q[j][4]:=q[j][4]+q[j-1][4]/q[j-1][2];
    end;
    for j:=m downto 1 do f[i][j]:=(q[j][4]-q[j][3]*f[i][j+1])/q[j][2];
  end;
  writeln(f[x][y]:0:10);
end.