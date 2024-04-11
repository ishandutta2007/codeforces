var
  n,i,k,t,t1,t2,t3,k1,k2,k3:longint;
  res:int64;
  lt,a:array[0..100500]of int64;
  procedure solve;
    begin
      for i:=1 to n do begin
        if (i>k)and(lt[i-k]>lt[i])then lt[i]:=lt[i-k];
        lt[i]:=lt[i]+t;
      end;
    end;
begin
  read(k1,k2,k3,t1,t2,t3,n);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do lt[i]:=a[i];
  k:=k1;t:=t1;solve;
  k:=k2;t:=t2;solve;
  k:=k3;t:=t3;solve;
  res:=0;
  for i:=1 to n do
    if (lt[i]-a[i]>res)then res:=lt[i]-a[i];
  writeln(res);
end.