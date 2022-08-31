var n,m,i,j,q,k,p,d,t:integer;
a,b,c:array [0..30] of int64;
x,y:int64;

begin
readln(n,m);
for i:=0 to 30 do a[i]:=0;
for i:=0 to 30 do b[i]:=0;
for j:=1 to n do
  begin
  read(x);
  for i:=0 to 30 do
    begin
    a[i]+=x shr i;
    end;
  end;
for i:=1 to m do
  begin
  read(x);
  b[x]+=1;
  end;
p:=0;
q:=m;
while p<q do
  begin
  k:=(p+q+1) shr 1;
  t:=1;
  for i:=0 to 30 do c[i]:=0;
  d:=0;
  for i:=0 to 30 do
    begin
    if d+b[i]<k then c[i]:=b[i] else
      begin
      c[i]:=k-d;
      break;
      end;
    d+=b[i];
    end;
  y:=0;
  for i:=30 downto 0 do
    begin
    y:=y*2+c[i];
    if y>a[i] then
      begin
      t:=0;
      break;
      end;
    end;
  if t=1 then p:=k else q:=k-1;
  end;
writeln(p);
end.