var
  ans,n,i:longint;

begin
  read(n);
  ans:=1;
  for i:=2 to n do ans:=ans+12*(i-1);
  writeln(ans);
end.