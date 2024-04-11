var
  tmp,k,n,i,j:longint;
  a,d:array[0..1111]of longint;
  was:array[0..1111,0..1111]of boolean;
  procedure dfs(x:longint);
    begin
      if (was[i][x])then exit;
      was[i][x]:=true;
      if (x>d[x])then dfs(x-d[x]);
      if (x+d[x]<=n)then dfs(x+d[x]);
    end;
begin
  read(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do read(d[i]);
  for i:=1 to n do dfs(i);
  for i:=1 to n do
    for j:=1 to n do
      was[i][j]:=was[i][j] or was[j][i];
  for k:=1 to n do
    for i:=1 to n do
      for j:=1 to n do
        if (was[i][k])and(was[k][j])then was[i][j]:=true;
  for j:=1 to n*n do
    for i:=1 to n do begin
      for k:=i+1 to n do
        if (was[i][k])and(a[i]>a[k])then begin
          tmp:=a[i];a[i]:=a[k];a[k]:=tmp;
        end;
      for k:=1 to i-1 do
        if (was[i][k])and(a[i]<a[k])then begin
          tmp:=a[i];a[i]:=a[k];a[k]:=tmp;
        end;
    end;
  for i:=1 to n do
    if (a[i]<>i)then begin
      writeln('NO');
      exit;
    end;
  writeln('YES');
end.