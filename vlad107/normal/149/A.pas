var
  sum,n,i,j,tmp:longint;
  a:array[0..5555]of longint;

begin
  read(n);
  for i:=1 to 12 do read(a[i]);
  for i:=1 to 11 do 
    for j:=1 to 11 do 
      if (a[j]<a[j+1])then begin
        tmp:=a[j];a[j]:=a[j+1];a[j+1]:=tmp;
      end;
  sum:=0;
  i:=1;
  while (sum<n)and(i<=12)do begin
    inc(sum,a[i]);
    inc(i);
  end;
  if (sum<n)then i:=0;
  writeln(i-1);
end.