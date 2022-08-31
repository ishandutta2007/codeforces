var x,n,i,j:integer;
a:array [1..100] of integer;
begin
readln(n);
for j:=1 to n do
  begin
  x:=0;
  for i:=1 to n do
    begin
    read(a[i]);
    if i<>j then x:=x or a[i];
    end;
  write(x,' ');
  end;
end.