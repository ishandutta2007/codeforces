const
  base=1000000007;

var
  f0,f1,i,n:longint;

begin
  read(n);
  f0:=1;
  f1:=0;
  for i:=2 to n do
    if (i and 1=0)
      then f1:=(f0+f1+1)mod base
      else f0:=(f0+f1+1)mod base;
  writeln((f0+f1)mod base);
end.