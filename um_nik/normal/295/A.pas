var n,m,k,i,x,y,j:integer;
p:int64;
a,l,r,d,b,c:array [0..100100] of int64;

begin
readln(n,m,k);
for i:=1 to n do read(a[i]);
for i:=1 to m do readln(l[i],r[i],d[i]);
for i:=0 to m+1 do c[i]:=0;
for i:=1 to k do
  begin
  readln(x,y);
  c[x]+=1;
  c[y+1]-=1;
  end;
p:=0;
for i:=1 to n do b[i]:=0;
for i:=1 to m do
  begin
  p+=c[i];
  b[l[i]]+=d[i]*p;
  b[r[i]+1]-=d[i]*p;
  end;
p:=0;
for i:=1 to n do
  begin
  p+=b[i];
  write(a[i]+p,' ');
  end;
end.