var
  ans,n,max,min,i,x:longint;

begin
  read(n);
  read(max);
  min:=max;
  ans:=0;
  for i:=2 to n do begin
    read(x);
    if (x<=max)and(x>=min)then continue;
    inc(ans);
    if (x>max)then max:=x;
    if (x<min)then min:=x;
  end;
  writeln(ans);
end.