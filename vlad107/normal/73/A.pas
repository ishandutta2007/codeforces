var
  tmp,i,j,k,a,b,c:longint;
  res:int64;
  x:array[0..5]of longint;

begin
  for i:=1 to 3 do read(x[i]);
  for i:=1 to 3 do dec(x[i]);
  read(k);
  for i:=1 to 2 do 
    for j:=1 to 2 do 
      if (x[j]<x[j+1])then begin
        tmp:=x[j];x[j]:=x[j+1];x[j+1]:=tmp;
      end;
  res:=0;
  for a:=0 to x[1] do begin
    b:=(k-a+1)shr 1;
    c:=k-a-b;
    if (c>x[3])then begin
      inc(b,c-x[3]);
      c:=x[3];
    end;
    if (b>x[2])then b:=x[2];
    if (int64(a+1)*(b+1)*(c+1)>res)then res:=int64(a+1)*(b+1)*(c+1);
  end;
  writeln(res);
end.