const
  base=1000000009;
var
  n,i:longint;
  f,g:array[0..1111111]of int64;
begin
  read(n);
  n:=n shr 1;
  g[0]:=0;
  for i:=1 to n do g[i]:=(g[i-1]+2)*2 mod base;
  f[0]:=0;
  for i:=1 to n-1 do 
    f[i]:=(f[i-1]+4)*(g[n-i-1]+1)mod base;
  writeln(2*((f[n-1]+2)*(f[n-1]+2)+1) mod base);
end.