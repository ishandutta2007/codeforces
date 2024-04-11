var
  res,n,i,x:longint;
  used:array[0..500500]of boolean;

begin
  read(n);
  res:=0;
  for i:=1 to n do begin
    read(x);
    if (x>n)or(used[x])then inc(res) else used[x]:=true;
  end;
  writeln(res);
end.