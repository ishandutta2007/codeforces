uses
  math;

var
  ans:extended;
  n,l,k,i,j,q:longint;
  f:array[0..222,-202..202,0..222]of extended;
  a,p:array[0..222]of longint;

begin
  read(n,l,k);
  for i:=1 to n do read(p[i]);
  for i:=1 to n do read(a[i]);
  f[1][min(k,n)][0]:=1;
  for i:=1 to n do 
    for j:=-n to n do 
      for q:=0 to l do begin
        if (f[i][j][q]=0)then continue;
        f[i+1][min(j+a[i],n)][min(q+1,l)]:=f[i+1][min(j+a[i],n)][min(q+1,l)]+f[i][j][q]*p[i]/100;
        f[i+1][j][q]:=f[i+1][j][q]+f[i][j][q]*(100-p[i])/100;
      end;
  ans:=0;
  for j:=0 to n do 
    ans:=ans+f[n+1][j][l];
  writeln(ans:0:10);
end.