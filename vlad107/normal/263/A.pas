var
  a:array[0..55,0..55]of longint;
  i,j:longint;

begin
  for i:=1 to 5 do for j:=1 to 5 do read(a[i][j]);
  for i:=1 to 5 do 
    for j:=1 to 5 do 
      if (a[i][j]=1)then begin
        writeln(abs(i-3)+abs(j-3));
        exit;
      end;
end.