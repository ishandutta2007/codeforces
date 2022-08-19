var z,n,m,k,i,j:integer;
a:array [1..50] of integer;
begin
readln(n,m,k);
m:=m-k;
for i:=1 to n do
  begin
  read(a[i]);
  a[i]-=1;
  end;
for i:=1 to n-1 do
  begin
  for j:=1 to n-i do
    begin
    if a[j]<a[j+1] then
      begin
      z:=a[j];
      a[j]:=a[j+1];
      a[j+1]:=z;
      end;
    end;
  end;
if m<=0 then writeln(0) else
  begin
  k:=0;
  for i:=1 to n do
    begin
    k+=a[i];
    if k>=m then
      begin
      writeln(i);
      break;
      end;
    end;
  if k<m then writeln(-1);
  end;
end.