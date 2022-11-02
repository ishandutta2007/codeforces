var
  n,i,j,k:longint;
  a:array[1..1000] of longint;

begin
  read(n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do 
    for j:=1 to n do  if (j<>i)then 
      for k:=1 to n do if (k<>i) and (k<>j)  then 
        if (a[i]=a[j]+a[k])
          then begin
            writeln(i, ' ',j, ' ',k,' ');
            exit;
          end;
  writeln(-1);
end.