var
  t,time:longint;
  a:array[1..4]of longint;

begin
  read(a[1],a[2],a[3]);
  t:=1;
  time:=29;
  while (a[1]+a[2]+a[3]>0)do begin
    inc(time);
    if (a[t]<2)then a[t]:=0 else dec(a[t],2);
    inc(t);
    if (t>3)then t:=1;
  end;
  writeln(time);
end.