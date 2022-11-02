var
  n,m,k,i:longint;

begin
  read(n,m);
  if (n<m)then k:=n else k:=m;
  writeln(k+1);
  for i:=0 to k do writeln(n-i,' ',i);
end.