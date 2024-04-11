var
  x,y,res,i,n,m:longint;
  pred:array[0..500500]of longint;
  function fs(x:longint):longint;
    begin
      if (pred[x]<>x)then pred[x]:=fs(pred[x]);
      fs:=pred[x];
    end;
begin
  read(n,m);
  res:=1;
  for i:=1 to n do pred[i]:=i;
  for i:=1 to m do begin
    read(x,y);
    x:=fs(x);
    y:=fs(y);
    if (x=y)
      then res:=(res+res)mod 1000000009
      else pred[y]:=x;
    writeln(res-1);
  end;
end.