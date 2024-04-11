var
  kol,n,sum,i:longint;
  a:array[0..500500]of longint;

begin
  read(n);
  sum:=0;
  for i:=1 to n do begin
    read(a[i]);
    sum:=sum+a[i];
  end;
  kol:=0;
  for i:=1 to n do 
    if ((sum-a[i])=a[i]*(n-1))then inc(kol);
  writeln(kol);
  for i:=1 to n do 
    if ((sum-a[i])=a[i]*(n-1))then write(i,' ');
  writeln;
end.