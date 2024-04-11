var n,m,i,x,y,k,p,j:integer;
a:array [1..400000,-2..10] of integer;
begin
readln(n,m);
for i:=1 to n do
  begin
  a[i,0]:=0;
  a[i,-1]:=0;
  a[i,-2]:=0;
  end;
for i:=1 to m do
  begin
  readln(x,y);
  a[x,0]+=1;
  a[x,a[x,0]]:=y;
  a[y,0]+=1;
  a[y,a[y,0]]:=x;
  a[x,-2]+=1;
  a[y,-2]+=1
  end;
k:=1;
while k>0 do
  begin
  k:=0;
  for i:=1 to n do
    begin
    if a[i,-2]>1 then
      begin
      k:=1;
      a[i,-2]:=a[i,0]-a[i,-2];
      a[i,-1]:=1-a[i,-1];
      for j:=1 to a[i,0] do
        begin
        if a[a[i,j],-1]=a[i,-1] then a[a[i,j],-2]+=1 else a[a[i,j],-2]-=1;
        end;
      end;
    end;
  end;
for i:=1 to n do write(a[i,-1]);
writeln();
end.