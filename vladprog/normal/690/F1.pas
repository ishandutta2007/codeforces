var
  n,a,b,i,ans:longint;
  k:array[1..10000]of longint;

begin
  read(n);
  //fillchar(k,sizeof(k),0);
  for i:=1 to n-1 do
    begin
      read(a,b);
      inc(k[a]);
      inc(k[b])
    end;
  ans:=0;
  for i:=1 to n do
    inc(ans,k[i]*(k[i]-1) div 2);
  writeln(ans)
end.