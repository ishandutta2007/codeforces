var n,m,i:integer;
ans:int64;
a:array [0..100100] of int64;
begin
readln(n,m);
for i:=1 to m do read(a[i]);
a[0]:=1;
ans:=0;
for i:=1 to m do
  begin
  if a[i]>=a[i-1] then ans+=a[i]-a[i-1] else ans+=n-a[i-1]+a[i];
  end;
writeln(ans);
end.