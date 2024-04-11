{$r-,q-,s-,i-,o+}
var
  a,nom:array[0..2000500]of longint;
  ii,k,nk,b,i,j,n:longint;

begin
  read(n);
  for i:=1 to n do a[i]:=i;
  b:=1;
  for k:=2 to n do begin
    inc(b);
    if (n mod k<>0)then a[b+n-1]:=a[b-1+n-(n mod k)];
    for j:=n div k downto 1 do begin
      ii:=j*k;
      nk:=ii-k+1;
      if (nk<1)then nk:=1;
      a[b+ii-1]:=a[b-1+nk-1];
    end;
  end;
  for i:=0 to n-1 do write(a[i+b],' ');
  writeln;
end.