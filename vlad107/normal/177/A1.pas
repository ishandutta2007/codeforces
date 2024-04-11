var
  sum,i,j,n:longint;
  u:array[0..1111,0..1111]of boolean;
  a:array[0..1111,0..1111]of longint;

begin
  read(n);
  for i:=1 to n do for j:=1 to n do read(a[i][j]);
  fillchar(u,sizeof(u),false);
  for i:=1 to n do begin
    u[i][i]:=true;
    u[i][n-i+1]:=true;
    u[(n+1)shr 1][i]:=true;
    u[i][(n+1)shr 1]:=true;
  end;
  sum:=0;
  for i:=1 to n do 
    for j:=1 to n do 
      if (u[i][j])then inc(sum,a[i][j]);
  writeln(sum);      
end.