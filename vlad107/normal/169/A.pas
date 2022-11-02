var
  a:array[0..500500]of longint;
  tmp,n,x,i,j:longint;

begin
  read(n,x,x);
  for i:=1 to n do read(a[i]);
  for i:=1 to n-1 do 
    for j:=1 to n-1 do 
      if (a[j]>a[j+1])then begin
        tmp:=a[j];a[j]:=a[j+1];a[j+1]:=tmp;
      end;
  writeln(a[x+1]-a[x]);      
end.