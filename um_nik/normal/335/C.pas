var r,n,i,j,k,ans,s,m,p:integer;
a,b:array [1..100,1..2] of integer;

g:array [0..110,1..4] of integer;
d:array [0..300] of integer;


begin

g[0,1]:=0;
g[0,2]:=1;
g[0,3]:=0;
g[0,4]:=1;
g[1,1]:=1;
g[1,2]:=2;
g[1,3]:=1;
g[1,4]:=0;
g[2,1]:=0;
g[2,2]:=3;
g[2,3]:=0;
g[2,4]:=1;
for i:=3 to 100 do
  begin
  
  // [n,1]
  for j:=0 to 200 do d[j]:=0;
  d[g[i-2,2]]:=1;
  for k:=0 to i-3 do d[g[i-3-k,2] xor g[k,2]]:=1;
  for j:=0 to 200 do
    begin
    if d[j]=0 then
      begin
      g[i,1]:=j;
      break;
      end;
    end;
  
  // [n,2]
  for j:=0 to 200 do d[j]:=0;
  d[g[i-2,3]]:=1;
  d[g[i-2,4]]:=1;
  d[g[i-1,2]]:=1;
  d[g[i-2,2]]:=1;
  d[g[i-2,2] xor 1]:=1;
  for k:=0 to i-3 do
    begin
    d[g[i-3-k,3] xor g[k,2]]:=1;
    d[g[i-3-k,4] xor g[k,2]]:=1;
    end;
  for j:=0 to 200 do
    begin
    if d[j]=0 then
      begin
      g[i,2]:=j;
      break;
      end;
    end;
  
  // [n,3]
  for j:=0 to 200 do d[j]:=0;
  d[g[i-1,3]]:=1;
  d[g[i-2,3] xor 1]:=1;
  d[g[i-2,4]]:=1;
  for k:=0 to i-3 do
    begin
    d[g[i-3-k,3] xor g[k,3]]:=1;
    d[g[i-3-k,4] xor g[k,4]]:=1;
    end;
  for j:=0 to 200 do
    begin
    if d[j]=0 then
      begin
      g[i,3]:=j;
      break;
      end;
    end;
  
  // [n,4]
  for j:=0 to 200 do d[j]:=0;
  d[g[i-1,4]]:=1;
  d[g[i-2,3]]:=1;
  d[g[i-2,4] xor 1]:=1;
  for k:=0 to i-3 do
    begin
    d[g[i-3-k,3] xor g[k,4]]:=1;
    end;
  for j:=0 to 200 do
    begin
    if d[j]=0 then
      begin
      g[i,4]:=j;
      break;
      end;
    end;
  
  end;

readln(r,n);
for i:=1 to n do readln(a[i,1],a[i,2]);
for i:=1 to n-1 do
  begin
  for j:=1 to n-i do
    begin
    if a[j,1]>a[j+1,1] then
      begin
      k:=a[j,1];
      a[j,1]:=a[j+1,1];
      a[j+1,1]:=k;
      k:=a[j,2];
      a[j,2]:=a[j+1,2];
      a[j+1,2]:=k;
      end;
    end;
  end;
if n=0 then
  begin
  k:=1;
  b[1,1]:=r;
  b[1,2]:=1;
  end else
  begin
  k:=0;
  if a[1,1]>1 then
    begin
    k+=1;
    b[k,1]:=a[1,1]-2;
    b[k,2]:=2;
    end;
  for i:=2 to n do
    begin
    if a[i,1]-a[i-1,1]=1 then continue;
    k+=1;
    if a[i,2]=a[i-1,2] then
      begin
      if a[i,1]-a[i-1,1]=2 then
        begin
        b[k,1]:=0;
        b[k,2]:=2;
        end else
        begin
        b[k,1]:=a[i,1]-a[i-1,1]-3;
        b[k,2]:=3;
        end;
      end else
      begin
      if a[i,1]-a[i-1,1]=2 then
        begin
        k-=1;
        end else
        begin
        b[k,1]:=a[i,1]-a[i-1,1]-3;
        b[k,2]:=4;
        end;
      end;
    end;
  if a[n,1]<r then
    begin
    k+=1;
    b[k,1]:=r-a[n,1]-1;
    b[k,2]:=2;
    end;
  end;
ans:=0;
//for i:=1 to k do writeln(b[i,1],' ',b[i,2]);
for i:=1 to k do ans:=ans xor g[b[i,1],b[i,2]];
if ans>0 then writeln('WIN') else writeln('LOSE');
end.