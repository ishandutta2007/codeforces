var i,n,k,ans:integer;
c,t,a,b:array [-2..100100] of integer;

procedure f(x:integer);
begin
if c[x]=-2 then
  begin
  c[x]:=0;
  exit;
  end;
if c[x]>-1 then exit;
if b[x]<1 then c[x]:=t[x] else
  begin
  c[x]:=-2;
  f(b[x]);
  if c[b[x]]>0 then c[x]:=c[b[x]]+1;
  end;
end;

begin
readln(n);
for i:=1 to n do read(t[i]);
for i:=1 to n do read(a[i]);
for i:=1 to n do b[i]:=0;
for i:=1 to n do
  begin
  if a[i]>0 then
    begin
    if b[a[i]]=0 then b[a[i]]:=i else b[a[i]]:=-1;
    end;
  end;
k:=0;
for i:=1 to n do c[i]:=-1;
for i:=1 to n do
  begin
  if c[i]=-1 then f(i);
  if c[i]>k then
    begin
    k:=c[i];
    ans:=i;
    end;
  end;
writeln(k);
for i:=1 to k do
  begin
  write(ans,' ');
  ans:=b[ans];
  end;
end.