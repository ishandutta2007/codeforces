var
  n,i,x,y,z,ans:longint;

begin
  read(n);
  ans:=0;
  for i:=1 to n do begin
    read(x,y,z);
    if (x+y+z>=2)then inc(Ans);
  end;
  writeln(ans);
end.