var
  tmp,max,n,i,j,kol,c:longint;
  a:array[1..10000]of longint;
begin
  read(n);
  for i:=1 to n do read(a[i]);
  for j:=1 to n-1 do
    for i:=1 to n-1 do 
      if (a[i]>a[i+1])then begin
        tmp:=a[i];a[i]:=a[i+1];a[i+1]:=tmp;
      end;
  c:=1;
  kol:=1;
  a[n+1]:=0;
  max:=0;
  for i:=2 to n+1 do 
    if (a[i]=a[i-1])then inc(c)else begin
      if (c>max)then max:=c;
      inc(kol);
      c:=1;
    end;
  writeln(max,' ',kol-1);
end.