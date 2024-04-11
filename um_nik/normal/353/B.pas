var n,i,x,y,z:integer;
a:array [0..100] of integer;
b,c:array [1..200] of integer;

begin
for i:=1 to 100 do a[i]:=0;
readln(n);
for i:=1 to 2*n do
  begin
  read(x);
  a[x]+=1;
  b[i]:=x;
  end;
x:=0;
y:=0;
for i:=10 to 99 do
  begin
  if a[i]>0 then
    begin
    if a[i]=1 then x+=1 else y+=1;
    end;
  end;
z:=x div 2;
writeln((y+z)*(y+x-z));
x:=1;
for i:=10 to 99 do
  begin
  if a[i]=1 then
    begin
    for y:=1 to 2*n do
      begin
      if b[y]=i then
        begin
        c[y]:=x;
        x:=3-x;
        end;
      end;
    end;
  end;
for i:=10 to 99 do
  begin
  if a[i]>1 then
    begin
    for y:=1 to 2*n do
      begin
      if b[y]=i then
        begin
        c[y]:=x;
        x:=3-x;
        end;
      end;
    end;
  end;
for i:=1 to 2*n do write(c[i],' ');
end.