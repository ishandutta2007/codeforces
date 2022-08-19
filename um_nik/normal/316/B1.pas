var n,i,j,k,x,y,z,p:integer;
a,b,c,d:array [0..1010] of integer;
e:array [0..1010,0..2010] of integer;

procedure dfs(g:integer);
begin
if b[g]=0 then exit;
c[b[g]]:=c[g];
dfs(b[g]);
end;

begin
readln(n,x);
for i:=1 to n do b[i]:=0;
for i:=1 to n do read(a[i]);
for i:=1 to n do
  begin
  if a[i]<>0 then b[a[i]]:=i;
  end;
k:=0;
for i:=1 to n do
  begin
  if a[i]=0 then
    begin
    k+=1;
    c[i]:=k;
    dfs(i);
    end;
  end;
y:=c[x];
for i:=1 to k do d[i]:=0;
for i:=1 to n do d[c[i]]+=1;
z:=d[k];
d[k]:=d[y];
d[y]:=z;
for i:=1 to n do
  begin
  if (a[i]=0) and (c[i]=y) then p:=i;
  end;
z:=1;
while p<>x do
  begin
  z+=1;
  p:=b[p];
  end;
k-=1;
for i:=0 to k do
  for j:=0 to 2*n do e[i,j]:=0;
e[0,0]:=1;
for i:=0 to k-1 do
  begin
  for j:=0 to n do
    begin
    if e[i,j]=1 then
      begin
      e[i+1,j]:=1;
      e[i+1,j+d[i+1]]:=1;
      end;
    end;
  end;
for i:=0 to n do
  begin
  if e[k,i]=1 then writeln(i+z);
  end;
end.