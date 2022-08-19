var t,l,r,m,n,i,j:integer;
f,a:array [0..300000] of int64;
v:int64;

begin
readln(n,m);
for i:=1 to n do read(a[i]);
f[0]:=1;
f[1]:=1;
for i:=2 to n do f[i]:=(f[i-1]+f[i-2]) mod 1000000000;
for j:=1 to m do
  begin
  read(t);
  if t=1 then
    begin
    read(r,v);
    a[r]:=v;
    end else
    begin
    v:=0;
    read(l,r);
    for i:=l to r do
      begin
      v:=(v + a[i]*f[i-l]) mod 1000000000;
      end;
    writeln(v);
    end;
  end;
end.