var
  n,m,k,i,j,tmp:longint;
  a:array[0..500500]of longint;

begin
  read(n,m,k);
  for i:=1 to n do read(a[i]);
  for i:=1 to n-1 do
    for j:=1 to n-1 do
      if (a[j]<a[j+1])then begin
        tmp:=a[j];a[j]:=a[j+1];a[j+1]:=tmp;
      end;
  for i:=1 to n do begin
    if (k>=m)then begin
      writeln(i-1);
      exit;
    end;
    k:=k+a[i]-1;
  end;
  if (k>=m)
    then writeln(n)
    else writeln(-1);
end.