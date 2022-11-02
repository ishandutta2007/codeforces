var
  q,n,i,j,x:longint;
  t,ans,a,b:array[0..500500]of longint;
  g,rg:array[0..1111,0..1111]of longint;

begin
  read(n);
  for i:=1 to n do for j:=1 to n do read(g[i][j]);
  for i:=1 to n do for j:=1 to n do rg[i][g[i][j]]:=j;
  for i:=1 to n do read(a[i]);
  for i:=1 to n do b[a[i]]:=i;

  for i:=1 to n do ans[i]:=0;
  for i:=1 to n do
    for j:=1 to n do begin
      x:=0;
      for q:=1 to i do
        if ((x=0)or(b[x]>b[q]))and(q<>j)then x:=q;
      if (x=0)then continue;
      if (ans[j]=0)or(rg[j][x]<rg[j][ans[j]])then ans[j]:=x;
    end;
  for i:=1 to n do write(ans[i],' ');
  writeln;
end.