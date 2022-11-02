var
  q,i,j,n:longint;
  ans:int64;
  f:array[0..500500]of longint;

begin
  read(n);
  for i:=1 to n do read(f[i]);
  ans:=0;
  for i:=1 to n-1 do begin
    for j:=1 to 30 do 
      if (i+1 shl j<=n)then q:=j;
    ans:=ans+f[i];
    inc(f[i+1 shl q],f[i]);
    f[i]:=0;
    writeln(ans);
  end;
end.