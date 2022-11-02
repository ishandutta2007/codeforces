var
  n,n1,n2,i,j,min:longint;
  a:array[1..100000]of longint;
begin
  read(n);
  for i:=1 to n do read(a[i]);
  min:=trunc(1e9);
  for i:=1 to n do begin
    j:=(i mod n)+1;
    if (abs(a[j]-a[i])<min)
      then begin
        min:=abs(a[i]-a[j]);
        n1:=i;
        n2:=j;
      end;
  end;
  writeln(n1, ' ',n2);
end.