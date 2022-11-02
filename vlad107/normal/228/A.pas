var
  tmp,ans,i,j:longint;
  a:array[0..500500]of longint;

begin
  for i:=1 to 4 do read(a[i]);
  for i:=1 to 3 do 
    for j:=1 to 3 do 
      if (a[j]>a[j+1])then begin
        tmp:=a[j];a[j]:=a[j+1];a[j+1]:=tmp;
      end;
  ans:=0;
  for i:=1 to 4 do 
    if (a[i]<>a[i-1])then inc(ans);
  writeln(4-ans);
end.