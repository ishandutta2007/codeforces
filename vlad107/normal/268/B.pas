var
  n,i,res:longint;

begin
  read(n);
  res:=0;
  for i:=1 to n do res:=res+n-i+1+(i-1)*(n-i);
  writeln(res);
end.