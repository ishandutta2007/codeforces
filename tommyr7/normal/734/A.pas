var n,i,j,now1,now2:longint;
    x:char;
begin
  readln(n);
  now1:=0;now2:=0;
  for i:=1 to n do
  begin
    read(x);
    if (x='A') then inc(now1) else inc(now2);
  end;
  readln;
  if (now1>now2) then writeln('Anton')
  else if (now2>now1) then writeln('Danik')
  else writeln('Friendship');
end.