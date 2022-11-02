var
  mm,n,m,k,i,j,q:longint;
  f:array[0..1000,0..1000]of longint;
  was:array[0..1000]of boolean;
begin
//  assign(output,'output.txt');rewrite(output);
  read(n,m,k);
  if (n and 1=0)then begin
    writeln('Marsel');
    exit;
  end;
  i:=1;
  while (i*i<=m)do begin
    if (m mod i=0)then begin
      if (i<m)and(i>=k)then begin
        writeln('Timur');
        exit;
      end;
      if (m div i<m)and(m div i>=k)then begin
        writeln('Timur');
        exit;
      end;
    end;
    inc(i);
  end;
  writeln('Marsel');
{  fillchar(f,sizeof(f),$0);
  mm:=m;
  if (n>mm)then mm:=n;
  for j:=1 to mm do
    for i:=1 to mm do begin
      fillchar(was,sizeof(was),false);
      for q:=k to j-1 do
        if (j mod q=0)then was[f[i-1][j]xor f[j div q][q]]:=true;
      q:=0;
      while (was[q])do inc(q);
      f[i][j]:=q;
    end;
  for j:=k+k to mm do 
    if (f[1][j]=0)then writeln(j);
  writeln(f[n][m]);}
end.