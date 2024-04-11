var
  res:int64;
  n,i,x:longint;
  t:array[-50..50]of longint;

begin
  read(n);
  fillchar(t,sizeof(t),$0);
  for i:=1 to n do begin
    read(x);
    inc(t[x]);
  end;
  res:=0;
  for i:=1 to 10 do 
    res:=res+int64(t[i])*(t[-i]);
  if (t[0]>0)then res:=res+int64(t[0])*(t[0]-1) div 2;
  writeln(res);
end.