var
  i,n,m,k,kol,min,j : longint;
  a,b,c : array [1..1000] of longint;
begin
  {assign(input,'input.txt'); reset(input);
  assign(output,'output.txt'); rewrite(output);
  }readln(n,m,k);
  for i:=1 to m do read(a[i]);
  for i:=1 to k do read(b[i]);
  for i:=1 to m do
    for j:=1 to k do
      if (b[j] mod a[i])=0
        then inc(c[i]);
  min:=maxlongint;
  for i:=1 to m do
    if c[i]<min then min:=c[i];
  kol:=0;
  for i:=1 to m do
    if c[i]=min then inc(kol);
  writeln(kol);
  for i:=1 to m do if c[i]=min then write(i,' ');
end.