{$r-,q-,s-,i-,o+}
var
  a:array[0..2000500]of longint;
  k,i,j,n:longint;

begin
  read(n);
  for i:=1 to n do a[i]:=i;
  for k:=2 to n do begin
    a[k+n-1]:=a[k-1+n-(n mod k)];
    for j:=n div k downto 1 do a[k+j*k-1]:=a[j*k-1];
  end;
  for i:=1 to n do write(a[i+n-1],' ');
  writeln;
end.