var ans,x,i,j,m,n,k,p,q,t:integer;
a:array [1..100,1..100] of integer;
b:array [1..100,1..100] of integer;
c:array [1..100] of integer;

procedure dfs(y:integer);
var i:integer;
begin
for i:=1 to n do
  begin
  if (b[y,i]=1) and (c[i]=0) then
    begin
    c[i]:=1;
    dfs(i);
    end;
  end;
end;

begin
readln(n,m);
t:=0;
for i:=1 to n do
  begin
  for j:=1 to m do a[i,j]:=0;
  read(p);
  if p>0 then t:=1;
  for j:=1 to p do
    begin
    read(x);
    a[i,x]:=1;
    end;
  end;
for i:=1 to n do
  begin
  for j:=1 to n do b[i,j]:=0;
  end;
for i:=1 to n do
  begin
  for j:=1 to m do
    begin
    if a[i,j]=1 then
      begin
      for k:=i+1 to n do
        begin
        if (a[k,j]=1) then
          begin
          b[i,k]:=1;
          b[k,i]:=1;
          end;
        end;
      end;
    end;
  end;
if t=0 then writeln(n) else
  begin
  for i:=1 to n do c[i]:=0;
  ans:=0;
  for i:=1 to n do
    begin
    if c[i]=0 then
      begin
      c[i]:=1;
      ans+=1;
      dfs(i);
      end;
    end;
  writeln(ans-1);
  end;
end.