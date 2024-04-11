var
  res:extended;
  tmp,n,i,j:longint;
  r:array[0..500500]of longint;

begin
  read(n);
  for i:=1 to n do read(r[i]);
  for i:=1 to n-1 do 
    for j:=1 to n-1 do 
      if (r[j]<r[j+1])then begin 
        tmp:=r[j];r[j]:=r[j+1];r[j+1]:=tmp;
      end;
  res:=0;
  for i:=1 to n-1 do 
    if (i and 1=1)
      then res:=res+pi*r[i]*r[i]-pi*r[i+1]*r[i+1];
  if (n and 1=1)then res:=res+pi*r[n]*r[n];      
  writeln(res:0:10);
end.