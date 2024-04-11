{$r-,q-,s-,i-,o+}
var
  n,ans,i,j,k:longint;
  t,f:array[0..5001,0..5001]of longint;
  s,a:array[0..5001]of longint;

begin
  read(n);
  for i:=1 to n do read(a[i]);
  s[0]:=0;
  for i:=1 to n do s[i]:=s[i-1]+a[i];
  for i:=n downto 1 do begin
    f[i][n]:=1;
    k:=0;
    for j:=i to n-1 do begin
      if (k<j)then k:=j+1;
      while (k<=n)and(2*s[j]-s[i-1]>s[k])do inc(k);
      if (k>n)then begin
        f[i][j]:=-1000000000;
        continue;
      end;
      if (t[j+1][k]+1>f[i][j])then f[i][j]:=t[j+1][k]+1;
    end;
    t[i][n]:=f[i][n];
    for j:=n-1 downto i do 
      if (t[i][j+1]>f[i][j])
        then t[i][j]:=t[i][j+1]
        else t[i][j]:=f[i][j];
  end;
  ans:=0;
  for i:=1 to n do 
    if (f[1][i]>ans)then ans:=f[1][i];
  writeln(n-ans);
end.