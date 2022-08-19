var i,n,foo,bar,baz,quz,x:integer;
ans:real;
begin
readln(n);
foo:=0;
bar:=0;
baz:=0;
quz:=1;
for i:=1 to n do
  begin
  readln(x);
  foo+=x;
  bar+=1;
  if (foo*quz>=bar*baz) then
    begin
    baz:=foo;
    quz:=bar;
    end;
  end;
ans:=baz/quz;
writeln(ans:20:6);
end.