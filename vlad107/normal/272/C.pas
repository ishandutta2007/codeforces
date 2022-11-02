{$r-,q-,s-,i-,o+}
var
  w,h,t:int64;
  i,n,tt:longint;
  a:array[0..500500]of int64;

begin
  read(n);
  for i:=1 to n do reaD(a[i]);
  read(tt);
  t:=0;
  while (tt>0)do begin
    dec(tt);
    read(w,h);
    if (a[w]>t)then t:=a[w];
    writeln(t);
    t:=t+h;
  end;
end.