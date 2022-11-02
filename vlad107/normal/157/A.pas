var
  n,i,j,ans,x:longint;
  sx,sy:array[0..500500]of longint;

begin
  read(n);
  for i:=1 to n do 
    for j:=1 to n do begin
      read(x);
      inc(sx[i],x);
      inc(sy[j],x);
    end;
  ans:=0;
  for i:=1 to n do 
    for j:=1 to n do 
      if (sy[j]>sx[i])then inc(ans);
  writeln(ans);          
end.