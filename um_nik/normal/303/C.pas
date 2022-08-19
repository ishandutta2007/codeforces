var n,k,i,j,m,p,t,x,i1,i2,y:integer;
a,c:array [0..1000100] of integer;
b:array [0..1000100,0..10] of integer;
d,e:array [1..30] of integer;
begin
readln(n,k);
for i:=1 to n do read(a[i]);
for i:=0 to 1000000 do b[i,0]:=0;
for i:=1 to n-1 do
  for j:=i+1 to n do
    begin
    b[abs(a[i]-a[j]),0]+=1;
    if b[abs(a[i]-a[j]),0]<11 then b[abs(a[i]-a[j]),b[abs(a[i]-a[j]),0]]:=a[i];
    end;
if n<=k+1 then writeln(1) else
begin
m:=n-k-1;
while true do
  begin
  m+=1;
  p:=0;
  i:=1;
  while i*m<1000000 do
    begin
    if 2*b[i*m,0]>(k*(k+1)) then
      begin
      p:=100;
      break;
      end;
    if b[i*m,0]>0 then
      begin
      for i1:=1 to b[i*m,0] do d[i1+p]:=b[i*m,i1];
      p+=b[i*m,0];
      end;
    i+=1;
    if 2*p>k*(k+1) then break;
    end;
  if 2*p<=k*(k+1) then
    begin
    for i1:=1 to p do
      begin
      e[i1]:=0;
      for i2:=1 to i1 do
        begin
        if d[i1] mod m=d[i2] mod m then
          begin
          e[i2]+=1;
          break;
          end;
        end;
      end;
    t:=0;
    for i1:=1 to p do
      begin
      if e[i1]=3 then e[i1]:=2;
      if e[i1]=6 then e[i1]:=3;
      if e[i1]=10 then e[i1]:=4;
      t+=e[i1];
      if t>k then break;
      end;
    if t<=k then break;
    end;
  end;
writeln(m);
end;
end.