var a,b:int64;
    ans:longint;
begin
  readln(a,b);
  ans:=0;
  while (a<=b) do
  begin
    inc(ans);
    a:=a+a+a;
    b:=b+b;
  end;
  writeln(ans);
end.