var n,i,j,k,t,x,y,z:integer;
a:array [1..23] of integer;
b:array [1..9000000] of integer;
c:array [0..25] of integer;
d:array [1..23,0..50] of integer;


begin
readln(n);
for i:=1 to n do read(a[i]);
for i:=1 to 9000000 do b[i]:=1000000;
b[1]:=1;
c[0]:=1;
for i:=1 to 25 do c[i]:=2*c[i-1];
for i:=1 to 23 do
  begin
  for j:=0 to 50 do d[i,j]:=0;
  end;
for i:=2 to n do
  begin
  for j:=1 to i-1 do
    begin
    for k:=j to i-1 do
      begin
      if a[j]+a[k]=a[i] then
        begin
        d[i,0]+=1;
        if j<>k then d[i,d[i,0]]:=c[j]+c[k] else d[i,d[i,0]]:=c[j];
        end;
      end;
    end;
  end;
for i:=1 to c[n-1]-1 do
  begin
  if b[i]<>1000000 then
    begin
    x:=i;
    j:=0;
    while c[j]<=x do j+=1;
    y:=j;
    //writeln(i,' ',y);
    x+=c[y];
    if b[i]+1<b[x] then
      begin
      t:=0;
      for k:=1 to d[y+1,0] do
        begin
        if (x and d[y+1,k])=d[y+1,k] then
          begin
          t:=1;
          break;
          end;
        end;
      if t=1 then
        begin
        if b[x]>b[i]+1 then b[x]:=b[i]+1;
        end;
      end;
    for j:=0 to y-1 do
      begin
      if (x and c[j])<>0 then
        begin
        z:=x-c[j];
        t:=0;
        for k:=1 to d[y+1,0] do
          begin
          if (z and d[y+1,k])=d[y+1,k] then
            begin
            t:=1;
            break;
            end;
          end;
        if t=1 then
          begin
          if b[z]>b[i] then b[z]:=b[i];
          end;
        end;
      end;
    end;
  end;
x:=1000000;
for i:=c[n-1] to c[n]-1 do
  begin
  if b[i]<x then x:=b[i];
  end;
if x=1000000 then writeln(-1) else writeln(x);
end.