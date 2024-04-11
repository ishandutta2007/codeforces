var n,i,k,j,x,y:integer;
a:array [1..10000000] of boolean;
begin
for i:=1 to 10000000 do a[i]:=true;
a[1]:=false;
for i:=1 to trunc(sqrt(10000000))+5 do
  begin
  if a[i] then
    begin
    j:=i;
    while i*j<=10000000 do
      begin
      a[i*j]:=false;
      j+=1;
      end;
    end;
  end;
readln(n);
k:=0;
for i:=10 to 10000000 do
  begin
  if a[i] then
    begin
    x:=i;
    y:=0;
    while x>0 do
      begin
      y:=y*10+x mod 10;
      x:=x div 10;
      end;
    if (a[y]) and (i<>y) then k+=1;
    if k=n then
      begin
      writeln(i);
      break;
      end;
    end;
  end;
end.