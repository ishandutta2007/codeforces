var
  ans,n,m,x,y,i,j,k:longint;
  t:array[0..1,0..500500]of longint;
  a:array[0..1111,0..1111]of char;
  f:array[0..1111,0..1111,0..1]of longint;

begin
  readln(n,m,x,y);
  for i:=1 to n do begin
    for j:=1 to m do read(a[i][j]);
    readln;
  end;
  for j:=1 to m do begin
    t[0][j]:=0;
    t[1][j]:=0;
    for i:=1 to n do 
      if (a[i][j]='.')
        then inc(t[0][j])
        else inc(t[1][j]);
  end;
  fillchar(f,sizeof(f),$FF);
  f[1][1][0]:=t[0][1];
  f[1][1][1]:=t[1][1];
  for i:=1 to m-1 do 
    for j:=1 to m do 
      for k:=0 to 1 do 
        if (f[i][j][k]<>-1)then begin
          if (f[i+1][j+1][k]=-1)or(f[i][j][k]+t[k][i+1]<f[i+1][j+1][k])
            then f[i+1][j+1][k]:=f[i][j][k]+t[k][i+1];
          if (x<=j)and(j<=y)and((f[i+1][1][1-k]=-1)or(f[i][j][k]+t[1-k][i+1]<f[i+1][1][1-k]))
            then f[i+1][1][1-k]:=f[i][j][k]+t[1-k][i+1];
        end;
  ans:=1000000000;
  for j:=x to y do 
    for k:=0 to 1 do 
      if (f[m][j][k]<>-1)and(f[m][j][k]<ans)then ans:=f[m][j][k];
  writeln(ans);
end.