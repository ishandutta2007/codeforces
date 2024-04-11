{$r-,q-,s-,i-,o+}
const
  base=1000000007;

var
  i,j,n,sum:longint;
  f:array[1..4]of longint;

begin
  read(n);
  f[4]:=1;
  for i:=1 to n do begin
    sum:=0;
    for j:=1 to 4 do begin
      inc(sum,f[j]);
      if (sum>=base)then dec(sum,base);
    end;
    for j:=1 to 4 do begin
      f[j]:=sum-f[j];
      if (f[j]<0)then inc(f[j],base);
    end;
  end;
  writeln(f[4]);
end.