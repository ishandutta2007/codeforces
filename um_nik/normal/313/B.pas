var n,i,k,m,x,y:integer;
s:string;
a:array [0..100100] of integer;

begin
readln(s);
n:=length(s);
for i:=0 to n+1 do a[i]:=0;
for i:=1 to n-1 do
  begin
  if s[i]=s[i+1] then a[i]:=1;
  end;
for i:=1 to n do a[i]+=a[i-1];
readln(m);
for i:=1 to m do
  begin
  readln(x,y);
  writeln(a[y-1]-a[x-1]);
  end;
end.